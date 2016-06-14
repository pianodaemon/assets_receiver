//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Abstract StandAlone class implementation
//
//======================================================================

#include "skel/app_stand_alone.hpp"


//!---------------------------------------------------------------------
//! \brief
//!     Class constructor.
//!
app_stand_alone::app_stand_alone()
{

}

//!---------------------------------------------------------------------
//! \brief
//!     Class destructor.
//!
app_stand_alone::~app_stand_alone()
{

}


//!---------------------------------------------------------------------
//! \brief
//!     Standardize the skeleton of an algorithm in a base class
//!
//! \return
//!     If successful returns zero.
//!
int app_stand_alone::exec()
{
    int rc;

    rc = this->validate_params();

    if ( rc < APP_STAND_ALONE_SUCCEED )
    {
        rc = APP_STAND_ALONE_NOT_VALID_PARAMS;
    }
    else
    {

        rc = this->run_logger();

        if ( rc < APP_STAND_ALONE_SUCCEED )
        {
            rc = APP_STAND_ALONE_CANT_RUN_LOGGER;
        }
        else
        {

            rc = this->start();
   
            if ( rc < APP_STAND_ALONE_SUCCEED )
            {
                rc =  APP_STAND_ALONE_START_BAD;
            }
        }
    }

    return rc;
}
