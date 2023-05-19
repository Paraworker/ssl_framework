#ifndef SSL_CTX_H
#define SSL_CTX_H

#include "ssl_connection.h"
#include <memory>

class SslCtxInternal;

class SslCtx
{
public:
    SslCtx(bool isClient);

    ~SslCtx();

    int32_t init();

    int32_t uninit();

    int32_t certificate();

    SslConnectionSPtr createConnection();

private:
    std::shared_ptr<SslCtxInternal> m_internal;
};

#endif

