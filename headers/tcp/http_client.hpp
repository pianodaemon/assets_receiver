//======================================================================
//  Company:
//      Maxima, Software
//
//  Product:
//      Asset Receiver for Agnux ERP
//      Copyright 2016
//
//  \brief
//      Tcp Client header
//
//======================================================================

#ifndef __TCP_HTTP_CLIENT_HPP__
#define __TCP_HTTP_CLIENT_HPP__

#include <cstdlib>

struct server_reply
{
    char*  buffer;
    size_t length;
};

extern int
post_json_data( const char* url_ptr , char* data_ptr , size_t data_length , struct server_reply** sr_ptr );

extern void
server_reply_cleanup( struct server_reply* sr_ptr );

#endif  /* __TCP_HTTP_CLIENT_HPP__ */
