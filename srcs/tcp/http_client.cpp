#include "tcp/http_client.hpp"
#include <curl/curl.h>
#include <cstring>


struct pivot
{
    const char *readptr;
    long sizeleft;
};

static size_t
read_callback(void *ptr, size_t size, size_t nmemb, void *userp)
{
    struct pivot *pooh = (struct pivot *)userp;

    if( size * nmemb < 1 ) return 0;

    if( pooh->sizeleft )
    {
        *(char *)ptr = pooh->readptr[0];
        pooh->readptr++;
        pooh->sizeleft--;
        return 1;
    }

    return 0;
}

static size_t
write_handler( void* contents, size_t size, size_t nmemb, void* user_ptr )
{
    size_t realsize = size * nmemb;
    struct server_reply* mem = ( struct server_reply* ) user_ptr;

    mem->buffer = static_cast<char*>( realloc( mem->buffer, mem->length + realsize + 1 ) );

    if ( mem->buffer == nullptr )
    {
        realsize = 0;
    }
    else
    {
        memcpy( &( mem->buffer[ mem->length ] ), contents, realsize );
        mem->length += realsize;
        mem->buffer[ mem->length ] = 0;
    }

    return realsize;
}

extern int
post_json_data( const char* url_ptr , char* data_ptr , size_t data_length , server_reply** sr_ptr )
{
    int rc = 0;

    if( sr_ptr == NULL )
    {
        rc = -3003;
    }
    else
    {
        CURL*  curl = nullptr;
        CURLcode curl_rc;

        curl_global_init( CURL_GLOBAL_ALL );
        curl = curl_easy_init();

        if ( curl == nullptr )
        {
            rc = -3001;
        }
        else
        {
            struct pivot pooh = { data_ptr , (long)data_length };
            struct server_reply chunk = { static_cast<char*>( malloc(1) ) , 0 };

            struct curl_slist* headers = nullptr;
            curl_slist_append( headers, "Content-Type: application/json" );
            curl_easy_setopt( curl, CURLOPT_HTTPHEADER, headers );
            curl_easy_setopt( curl, CURLOPT_URL, url_ptr );
            curl_easy_setopt( curl, CURLOPT_USERAGENT, "libcurl-agent/1.0" );
            curl_easy_setopt( curl, CURLOPT_POST, 1L );
            curl_easy_setopt( curl, CURLOPT_WRITEDATA, (void *)&chunk );
            curl_easy_setopt( curl, CURLOPT_READDATA, &pooh );

            curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, write_handler);


            curl_easy_setopt( curl, CURLOPT_READFUNCTION, read_callback );

            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, pooh.sizeleft);

            curl_rc = curl_easy_perform( curl );

            if ( curl_rc == CURLE_OK )
            {
                *sr_ptr = new server_reply;

                if( *sr_ptr == nullptr )
                {
                    rc = -1;
                }
                else
                {
                    struct server_reply* sa = nullptr;

                    sa = *sr_ptr;

                    if( chunk.length > 0 )
                    {
                        sa->length = chunk.length;
                        sa->buffer = new char[ chunk.length ];
                        if( sa->buffer != nullptr ) memcpy( sa->buffer, chunk.buffer, chunk.length );
                        else rc = -1;
                    }
                }

            }
            else
            {
                rc = -3002;
            }

            free( chunk.buffer );

            curl_easy_cleanup( curl );
            curl_global_cleanup();
        }
    }

    return rc;
}

extern void
server_reply_cleanup( struct server_reply* sr_ptr )
{
    delete[] sr_ptr->buffer;
    delete sr_ptr;
}


