#include "defs.h"
#include "ssl_ctx_impl.h"

SslCtxInternal::SslCtxInternal(bool isClient)
    : m_isClient(isClient)
    , m_handle(nullptr)
{

}

SslCtxInternal::~SslCtxInternal()
{
    uninit();
}

int32_t SslCtxInternal::init()
{
    if (m_handle)
    {
        return ERROR_GENERAL;
    }

    if (m_isClient)
    {
        m_handle = SSL_CTX_new(TLS_client_method());
    }
    else
    {
        m_handle = SSL_CTX_new(TLS_server_method());
    }

    if (!m_handle)
    {
        return ERROR_GENERAL;
    }

    // set options for server
    if (!m_isClient)
    {
        // TODO: set options
    }

    return ERROR_NO;
}

int32_t SslCtxInternal::uninit()
{
    if (!m_handle)
    {
        return ERROR_GENERAL;
    }

    SSL_CTX_free(m_handle);

    return ERROR_NO;
}

int32_t SslCtxInternal::certificate()
{
    if (m_isClient)
    {
        return ERROR_GENERAL;
    }

    // TODO

    return ERROR_NO;
}