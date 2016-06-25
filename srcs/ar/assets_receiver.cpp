//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Asset Receiver class implementation
//
//======================================================================


#include "ar/assets_receiver.hpp"
#include "util/debug_tracer.hpp"
#include "term-ui/inceptor.hpp"
#include <curl/curl.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

#define __LOG_CONFIG_FILE "log_config.xml"

assets_receiver::assets_receiver( const int argc, char **argv )
{
    this->m_argc = argc;
    this->m_argv = argv;
}


assets_receiver::~assets_receiver()
{   

}


int assets_receiver::run_logger()
{
    int rc = ASSET_RECEIVER_SUCCEED;

    try
    {
        log4cxx::xml::DOMConfigurator::configure( __LOG_CONFIG_FILE );
    }
    catch( const log4cxx::helpers::Exception &e )
    {
        rc =  ASSET_RECEIVER_SYSTEM_ERROR;

        std::cout << "Fail through the Initializing of Debug Tracer : " << e.what() << std::endl;
    }

    return rc;
}


int assets_receiver::validate_params()
{
    int rc = ASSET_RECEIVER_SUCCEED;

    if ( this->m_argc < 2 )
    {
        std::cerr << "USAGE: " << this->m_argv[0] << " <erp_user>" << std::endl;

        rc = ASSET_RECEIVER_NOT_ENOUGH_ARGS;
    }
    
    return rc;
}


int assets_receiver::start()
{
    int rc = ASSET_RECEIVER_SUCCEED;

    DEBUG_TRACER_INFO( "Initialization of environment that CURL needs" );
    curl_global_init( CURL_GLOBAL_ALL );


    DEBUG_TRACER_INFO( "Go ahead with Terminal User interface" );
    ncurses_ui_go( this->m_argv[0] , this->m_argv[1] );


    DEBUG_TRACER_INFO( "Releases resources acquired by CURL" );
    curl_global_cleanup();

    return rc;
}
