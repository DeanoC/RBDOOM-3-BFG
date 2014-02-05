
#include <iostream>
#include <functional>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/detail/endian.hpp>

#include <cstdlib>
#include <cstdint>
#include "path_iterate.hpp"

#define PKM_MAGIC (unsigned int)( ('P'<<0)|('K'<<8)|('M'<<16)|(' '<<24) )

inline uint32_t swap_bytes( uint32_t& _data ) {
	_data = (((_data & 0x000000FF) >> 0) << 24) |
			(((_data & 0x0000FF00) >> 8) << 16) |
			(((_data & 0x00FF0000) >> 16) << 8) |
			(((_data & 0xFF000000) >> 24) << 0);

	return _data;
}


struct PkmHeader {
	uint32_t magic;
	uint16_t version;
	uint16_t format;
	uint16_t extendedWidth; 	// big endian
	uint16_t extendedHeight;	// big endian
	uint16_t originalWidth;		// big endian
	uint16_t originalHeight;	// big endian
	// 64 big endian data follows
};

// from doom3 BinaryImageData.h
// Values are big endien to reduce effort on consoles.
#define BIMAGE_VERSION 10
#define BIMAGE_MAGIC (unsigned int)( ('B'<<0)|('I'<<8)|('M'<<16)|(BIMAGE_VERSION<<24) )

struct Doom3BImageImage {
	uint32_t		level;
	uint32_t		destZ;
	uint32_t		width;
	uint32_t		height;
	uint32_t		dataSize;
	// dataSize bytes follow
};

struct Doom3BImageFileHeader {
	int64_t		sourceFileTime;
	uint32_t	headerMagic;
	uint32_t	textureType;
	uint32_t	format;
	uint32_t	colorFormat;
	uint32_t	width;
	uint32_t	height;
	uint32_t	numLevels;
	// one or more bimageImage_t structures follow
};

int main( int argc, char* argv[] ) {

	std::string speed = "fast";
	std::string path;
	if( argc == 3 ) {
		if( std::string(argv[1]) == "--slow" ) {
			speed = "slow";
			path = argv[2];
		} else {
			std::cout << "Usage : compressGenerated --slow generated_path\n";
			return 1;
		}
	} else if( argc == 2 ) {
		if( std::string(argv[1]) == "--slow" ) {
			std::cout << "Usage : compressGenerated --slow generated_path\n";
			return 1;
		} else {
			path = argv[1];
		}
	} else {
		std::cout << "Usage : compressGenerated --slow generated_path\n";
		return 1;		
	}

	boost::format cmdFormatter("./etcpack \"%s_%i_%s.tga\" \"%s\" -s %s -c etc2 -ext TGA -f %s %s");
	boost::format pkmFormatter( "%s_%i_%s.pkm" );

	path_iterate( argv[1], [&]( const boost::filesystem::directory_entry& _file ) {
		if( _file.path().has_extension() ) {
			auto ext = _file.path().extension().native();
			boost::algorithm::to_lower( ext );
			if(  ext == ".tga" ) {
				auto pathWithOutExt = _file.path();
				pathWithOutExt.replace_extension("");
				const std::string tgaName = pathWithOutExt.native();

				// break up file name
				const auto cutPoint0 = tgaName.find_last_of( "_" );
				const std::string format( tgaName, cutPoint0+1 );
				const std::string nameWithMiplevel( tgaName, 0, cutPoint0 );
				const auto cutPoint1 = nameWithMiplevel.find_last_of( "_" );
				const std::string mipLevelString( tgaName, cutPoint1+1, cutPoint0 - cutPoint1 - 1 );
				const std::string baseName( tgaName, 0, cutPoint1 );

				// now search for 
				boost::filesystem::directory_iterator rdIt( _file.path().parent_path() );
				std::find_if( rdIt, boost::filesystem::directory_iterator(), [&]( const boost::filesystem::directory_entry& _inPath ) -> bool {
					auto biext = _inPath.path().extension().native();
					boost::algorithm::to_lower( biext );
					if( biext == ".bimage" ) {
						/* diagnostic code
						std::cout << ".bimage: " <<_inPath.path().native() << "\n";
						std::cout << "format: " << format << "\n";
						std::cout << "name with mip: " << nameWithMiplevel << "\n";
						std::cout << "mip level: " << mipLevelString << "\n";
						std::cout << "name: " << baseName << "\n";
						*/						
						return true;
					} else {
						return false;
					}
				} );

				if( rdIt == boost::filesystem::directory_iterator() ) {
					std::cout << "TGA without bimage file: " << tgaName << "\n";					
					return;
				}


				const auto outputPath = _file.path().parent_path().native();
				const std::string binaryName = rdIt->path().native();

				Doom3BImageFileHeader bimageFileHeader;
				FILE* origBImageFH = fopen( binaryName.c_str(), "rb" );			
				int bytesGot = fread( &bimageFileHeader, 1, sizeof(Doom3BImageFileHeader), origBImageFH );
				if( bytesGot != sizeof(Doom3BImageFileHeader) ) {
					std::cout << "File read error: " << binaryName << "\n";					
				}
				fclose( origBImageFH );
#ifdef BOOST_LITTLE_ENDIAN
				swap_bytes( bimageFileHeader.headerMagic );
				swap_bytes( bimageFileHeader.textureType );
				swap_bytes( bimageFileHeader.format );
				swap_bytes( bimageFileHeader.colorFormat );
				swap_bytes( bimageFileHeader.width );
				swap_bytes( bimageFileHeader.height );
				swap_bytes( bimageFileHeader.numLevels );
#endif
				if( bimageFileHeader.headerMagic != BIMAGE_MAGIC ) {
					std::cout << "Invalid Doom3 Binary Image File\n";
				}

				std::string fmt( "RGBA8" );
				if( bimageFileHeader.format == 7 ) { // DXT 1
					fmt = "RGBA1";
				} else if( bimageFileHeader.format == 8 ) { // DXT 5
					fmt = "RGBA8";
				} else {
					// try filename extension
					if( format == "DXT1") {
						fmt = "RGBA1";
					} else {
						fmt = "RGBA8";
					}
				}

				std::string domips("");
				// NOTE: currently let doom3 generate the bitmaps, 
				//int mipLevel = 0; // uncomment here and in doom3 image_load.cpp for etcpack mipmaps
				// domips = "-mipmaps" 
				for( int mipLevel = 0;mipLevel < bimageFileHeader.numLevels; ++mipLevel )
				{
					const auto cmdLine = (cmdformatter % baseName % mipLevel % format % outputPath % speed % fmt %domips).str();
					int sysRet = system( cmdLine.c_str() );
					if( sysRet == 0 ) {
						// now load PKM file produced and convert into Doom3 Binary Image format
//						std::cout << cmdLine << "\n";
					} else {
						std::cerr << "Error running " << cmdLine << "\n";
						exit( 1 );
					}
				}
				
				const auto pkmName = (pkmFormatter % baseName % mipLevel % format).string();

				PkmHeader pkmHeader;
				FILE* pkmFH = fopen( pkmName.c_str(), "rb" );
				int pkmBytesGot = fread( &pkmHeader, 1, sizeof(PkmHeader), pkmFH );
				if( pkmBytesGot != sizeof(PkmHeader) ) {
					std::cout << "File read error: " << pkmName << "\n";					
				}

				exit( 0 );
			}
		}
	} );

	return 0;
}