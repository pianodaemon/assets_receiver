
#include "ar/assets_receiver.hpp"

#define __APP_NAME 0

int main( int argc , char* argv[] )
{
    assets_receiver app( argv[ __APP_NAME ] , argc , argv );

    return app.exec();
}
