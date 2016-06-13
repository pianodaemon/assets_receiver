#include "util/str_ascii_helper.hpp"
#include <algorithm>
#include <sstream>


extern std::string&
ltrim( std::string &s )
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}


extern std::string&
rtrim( std::string &s )
{
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}


extern std::string&
trim( std::string &s )
{
    return ltrim( rtrim( s ) );
}

static std::vector< std::string >&
split( const std::string &s , char delim , std::vector< std::string > &elems )
{
    std::stringstream ss( s );
    std::string item;
    while (std::getline( ss , item , delim ) )
    {
        elems.push_back( item );
    }
    return elems;
}

extern std::vector< std::string >
split( const std::string &s , char delim )
{
    std::vector< std::string > elems;
    split( s , delim , elems );
    return elems;
}

extern void
remove_code( char c , std::string &s )
{
    s.erase( std::remove( s.begin(), s.end(), c ), s.end() );
}

extern void 
rand_alpha_numeric( char* strout_ptr, const int len )
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for ( int i = 0; i < len; ++i ) 
    {
        strout_ptr[i] = alphanum[ rand() % ( sizeof(alphanum) - 1 ) ];
    }

    strout_ptr[len] = 0;
}
