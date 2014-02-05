#if !defined( PATH_ITERATE_H_ )
#define PATH_ITERATE_H_

#include <boost/filesystem.hpp>

void path_iterate( const std::string& _basePath, const std::function< void(const boost::filesystem::directory_entry&) > _fileCallback );

#endif