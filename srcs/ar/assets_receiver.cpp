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
#include <cstdlib>
#include <iostream>
#include <unistd.h>

#define __LOG_CONFIG_FILE "log_config.xml"

assets_receiver::assets_receiver( const char* app_name , int argc, char **argv ) : app_stand_alone( app_name )
{
    this->m_argc = argc;
    this->m_argv = argv;
}


assets_receiver::~assets_receiver()
{   
    DEBUG_TRACER_INFO( "Running assets_receiver destructor!." );
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
        std::cerr << "USAGE: " << this->get_app_name() << " <erp_user>" << std::endl;

        rc = ASSET_RECEIVER_NOT_ENOUGH_ARGS;
    }
    
    return rc;
}


int assets_receiver::start()
{
    int rc = ASSET_RECEIVER_SUCCEED;

    enum scr_registry
    {
        SCR_MAIN_MENU,
        SCR_RECV_MENU,
        //SCR_RECV_ASN_STEP_LOCATION,
        //SCR_RECV_ASN_STEP_SCAN,
        
    };

    DEBUG_TRACER_INFO( "Starting " << this->get_app_name() );

    std::string erp_user = this->m_argv[1];

    enum scr_registry current = SCR_MAIN_MENU;    

    for(;;)
    {
        switch( current )
        {
            case SCR_MAIN_MENU:
            {
                
                break;
            }
            case SCR_RECV_MENU:
            {

                break;
            }
        }
    }  


    return rc;
}
