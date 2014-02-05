
#include <boost/filesystem.hpp>

void path_iterate( const std::string& _basePath, const std::function< void(const boost::filesystem::directory_entry&) > _fileCallback ) {
	using namespace std;
	using namespace boost::filesystem;

	recursive_directory_iterator rdIt( _basePath );

	while( rdIt !=  recursive_directory_iterator() ) {
		const auto p = *rdIt;

		try {
			if( exists( p ) ) {
				if( is_regular_file( p ) ) {
					//cout << "file : " << p << '\n';
					_fileCallback( p );
				} else if( is_directory( p ) ) {
					//cout << "directory : " << p << '\n';
				} else {
					//cout << "odd file type : " << p << '\n';
				}
			}
		} catch ( const filesystem_error& ex ) {
			cout << ex.what() << '\n';
		}
		// next file
		++rdIt;
	}	

}