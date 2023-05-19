#ifndef SSL_CONNECTION_IMPL_H
#define SSL_CONNECTION_IMPL_H

#include "ssl_connection.h"
#include "ssl_ctx_impl.h"
#include "openssl/ssl.h"
#include <WinSock2.h>

class SslConnectionInternal
{
public:
    SslConnectionInternal(SslCtxInternalSPtr const& ctx);

    ~SslConnectionInternal();

    int32_t setFd(SOCKET fd);

    int32_t handshake();

    int32_t shutdown();

    int32_t send(const uint8_t* buf, size_t len);

    int32_t recv(uint8_t* buf, size_t len);

    static SslConnectionSPtr createConnection(SslCtxInternalSPtr const& ctx);

    static void connectionDeleter(SslConnection* connection);

private:
    SslCtxInternalSPtr m_ctx;
    SSL*               m_ssl;
};

#endif
