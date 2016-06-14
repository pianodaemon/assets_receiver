//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Tcp http client stuff header
//
//======================================================================

#ifndef __TCP_HTTP_CLIENT_STUFF_HPP__
#define __TCP_HTTP_CLIENT_STUFF_HPP__

#include "tcp/error_codes.hpp"
#include <cstdlib>

struct server_reply
{
    char*  buffer;
    size_t length;
};

//!----------------------------------------------------------------------
//!
//! \brief
//!    Perform a http post with a json string.
//!
//! \param [out]
//!     sr_ptr      Double pointer where server_reply is allocated
//!                 and builded.
//! \return
//!     int
//!
extern int
post_json_data( const char* url_ptr , char* data_ptr , size_t data_length , struct server_reply** sr_ptr );


//!----------------------------------------------------------------------
//!
//! \brief
//!    Free memory utilized by a server_reply.
//!
//! \param [in]
//!     sr_ptr      server_reply to be free.
//!                 
//! \return
//!     void
//!
extern void
server_reply_cleanup( struct server_reply* sr_ptr );

#endif  /* __TCP_HTTP_CLIENT_STUFF_HPP__ */
