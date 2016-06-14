//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Abstract Standalone header
//
//======================================================================

#ifndef __AR_APP_STANDALONE_HPP__
#define __AR_APP_STANDALONE_HPP__


#include <iostream>
#include <string>
#include "skel/error_codes.hpp"

//!=================================================================
//!
//! \brief
//!     Class to execute Abstract Application in standalone mode.
//!
//==================================================================
class app_stand_alone
{
    public:

        app_stand_alone();

        virtual ~app_stand_alone();

        //!=========================================================
        //!
        //! \brief
        //!      Standardize the skeleton of an algorithm in a 
        //!      base class.
        //!
        //! \return
        //!     int
        //!
        int exec();

    private:

        //!=========================================================
        //!
        //! \brief
        //!      Init the logger Engine selected
        //!
        //! \return
        //!     int
        //!
        virtual int run_logger() = 0;

        //!=========================================================
        //!
        //! \brief
        //!      Validate the command line params.
        //!
        //! \return
        //!     int
        //!
        virtual int validate_params() = 0;

        //!=========================================================
        //!
        //! \brief
        //!      Execute Application in standalone mode
        //!
        //! \return
        //!     int
        //!
        virtual int start() = 0;

};

#endif  /* __AR_APP_STANDALONE_HPP__ */
