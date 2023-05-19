#ifndef SSL_DEFS_H
#define SSL_DEFS_H

enum SslError
{
    ERROR_NO         = 0,
    ERROR_GENERAL    = -1,
    ERROR_WANT_READ  = -2,
    ERROR_WANT_WRITE = -3,
};

#endif
