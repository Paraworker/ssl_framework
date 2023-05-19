#ifndef SSL_INIT_H
#define SSL_INIT_H

#include "openssl/ssl.h"
#include "openssl/opensslv.h"

extern "C" bool sslInit()
{
    // returns 1 on success or 0 on error
    return OPENSSL_init_ssl(OPENSSL_INIT_LOAD_CONFIG, NULL) == 1;
}

#endif

