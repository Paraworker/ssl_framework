#ifndef SSL_CTX_IMPL_H
#define SSL_CTX_IMPL_H

#include "openssl/ssl.h"
#include <memory>

class SslCtxInternal
{
public:
    SslCtxInternal(bool isClient);

    ~SslCtxInternal();

    int32_t init();

    int32_t uninit();

    int32_t certificate();

    inline SSL_CTX* getHandle() { return m_handle; }

    inline bool isClient() { return m_isClient; }

private:
    SSL_CTX* m_handle;
    bool     m_isClient;
};

using SslCtxInternalSPtr = std::shared_ptr<SslCtxInternal>;

#endif
