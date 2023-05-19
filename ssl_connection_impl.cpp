#include "defs.h"
#include "ssl_connection_impl.h"
#include <assert.h>

SslConnectionInternal::SslConnectionInternal(SslCtxInternalSPtr const& ctx)
    : m_ctx(ctx)
    , m_ssl(nullptr)
{
    assert(m_ctx);
}

SslConnectionInternal::~SslConnectionInternal()
{
    if (m_ssl)
    {
        // TODO
    }
}

int32_t SslConnectionInternal::setFd(SOCKET fd)
{
    if (m_ssl)
    {
        return ERROR_GENERAL;
    }

    m_ssl = SSL_new(m_ctx->getHandle());
    if (!m_ssl)
    {
        return ERROR_GENERAL;
    }

    if (!SSL_set_fd(m_ssl, fd))
    {
        return ERROR_GENERAL;
    }

    if (m_ctx->isClient())
    {
        SSL_set_connect_state(m_ssl);
    }
    else
    {
        SSL_set_accept_state(m_ssl);
    }

    return ERROR_NO;
}

int32_t SslConnectionInternal::handshake()
{
    if (!m_ssl)
    {
        return ERROR_GENERAL;
    }

    int handshakeRet = SSL_do_handshake(m_ssl);
    if (handshakeRet == 1)
    {
        return ERROR_NO;
    }

    int err = SSL_get_error(m_ssl, handshakeRet);

    int32_t ret = ERROR_GENERAL;

    switch (err)
    {
    case SSL_ERROR_WANT_READ:
        ret = ERROR_WANT_READ;
        break;
    case SSL_ERROR_WANT_WRITE:
        ret = ERROR_WANT_WRITE;
        break;
    default:
        break;
    }

    return ret;
}

int32_t SslConnectionInternal::shutdown()
{
    // TODO

    return ERROR_NO;
}

int32_t SslConnectionInternal::send(const uint8_t* buf, size_t len)
{
    return ERROR_NO;
}

int32_t SslConnectionInternal::recv(uint8_t* buf, size_t len)
{
    return ERROR_NO;
}

SslConnectionSPtr SslConnectionInternal::createConnection(SslCtxInternalSPtr const& ctx)
{
    SslConnectionSPtr con(new SslConnection, connectionDeleter);
    assert(con);

    con->m_internal.reset(new SslConnectionInternal(ctx));

    return con;
}

void SslConnectionInternal::connectionDeleter(SslConnection* connection)
{
    delete connection;
}