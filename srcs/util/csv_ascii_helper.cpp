#include "util/csv_ascii_helper.hpp"
#include "util/str_ascii_helper.hpp"
#include <fstream>


extern int
read_csv( const char file[] , const char token , std::function<void(std::vector< std::string >&& v)> row_delegate )
{
    int rc = 0;

    if (file != nullptr)
    {
        std::ifstream inputStream;

        inputStream.open(file);

        std::string line;

        while ( std::getline(inputStream, line) )
	{
            remove_code('\n',line);
            row_delegate( split(line, token) );
        }

        inputStream.close();
    }
    else
    {
        rc = -1;
    }

    return rc;
}
