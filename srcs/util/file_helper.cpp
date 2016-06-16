#include "util/file_helper.hpp"
#include <cstring>
#include <glob.h>
#include <sys/stat.h>

extern std::vector<std::string>
globbing( const char pattern[] )
{
    std::vector<std::string> file_list_ret;
   
    glob_t globbuf;
    glob( pattern , GLOB_TILDE, NULL, &globbuf );
 
    for ( unsigned int i = 0; i < globbuf.gl_pathc; ++i )
    {
        file_list_ret.push_back( globbuf.gl_pathv[i] );
    }

    if( globbuf.gl_pathc > 0 ) globfree( &globbuf );
   
    return file_list_ret;
}

extern unsigned long
get_file_size( const char file[] )
{
    int rc;
    struct stat sb;

    rc = stat( file , &sb );

    if ( rc == 0 ) rc = sb.st_size;

    return rc;
}

extern const bool
check_dir_existence( const char path[] )
{
    bool rc;
    struct stat sb;

    rc = ( stat( path , &sb ) == 0 );

    if ( rc ) rc = S_ISDIR( sb.st_mode );
   
    return rc;
}


extern int
create_dir( const char pathname[] , const mode_t mode )
{
    auto incept_dir = []( const char path[] , const mode_t mode )
    {
        int rc = UTIL_SUCCEED;    
    
        if ( !check_dir_existence( path ) )
        {
            struct stat sb;
           
            if ( stat( path , &sb ) == 0 ) rc = UTIL_DIR_IS_ALREADY_FILE;
            else if ( mkdir( path, mode ) != 0 ) rc = UTIL_DIR_WASNT_CREATED;   
        }
        else rc = UTIL_DIR_ALREADY_EXISTS;
       
        return rc;
    };

    int rc = UTIL_SUCCEED;
   
    char* pp = nullptr;
    char* sp = nullptr;
    char* copypath = nullptr;
       
    copypath = strdup( pathname );
    pp = copypath;
       
    while ( ( rc == UTIL_SUCCEED ) && ( ( sp = strchr( pp , '/' ) ) != 0 ) )
    {
        if ( sp != pp )
        {
            *sp = '\0';
            rc = incept_dir( copypath , mode );

            if ( rc == UTIL_DIR_ALREADY_EXISTS ) rc = UTIL_SUCCEED;  

            *sp = '/';
        }
        pp = sp + 1;
    }
       
    if ( rc == UTIL_SUCCEED ) rc = incept_dir( pathname , mode );
       
    free( copypath );
       
    return rc;
}
