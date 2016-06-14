//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Application Stand Alone header
//
//======================================================================

#ifndef __AR_ASSETS_RECEIVER_HPP__
#define __AR_ASSETS_RECEIVER_HPP__

#include "skel/app_stand_alone.hpp"
#include "ar/error_codes.hpp"
//!=================================================================
//!
//! \brief
//!     Class to execute Assets Receiver app in standalone mode.
//!
//==================================================================
class assets_receiver : public app_stand_alone
{
    public:

        //!=========================================================
        //!
        //! \brief
        //!     Class constructor.
        //!
        assets_receiver( const int argc , char **argv );


        //!=========================================================
        //!
        //! \brief
        //!     Class destructor.
        //!
        virtual ~assets_receiver();

    private:

        //!=========================================================
        //!
        //! \brief
        //!      Init the logger Engine selected.
        //!
        //! \return
        //!     int.
        //!
        int run_logger();

        //!=========================================================
        //!
        //! \brief
        //!      Validate the command line params.
        //!
        //! \return
        //!     int.
        //!
        int validate_params();

        //!=========================================================
        //!
        //! \brief
        //!      Execute Application in standalone mode
        //!
        //! \return
        //!     int.
        //!
        int start();


    private:

        int m_argc;
        char **m_argv;

};

#endif  /* __AR_ASSETS_RECEIVER_HPP__ */
