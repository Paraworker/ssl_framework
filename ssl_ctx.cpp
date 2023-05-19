#include "ssl_ctx.h"
#include "ssl_ctx_impl.h"
#include "ssl_connection.h"
#include "ssl_connection_impl.h"
#include <assert.h>

SslCtx::SslCtx(bool isClient)
    : m_internal(new SslCtxInternal(isClient))
{
    assert(m_internal);
}

SslCtx::~SslCtx()
{

}

int32_t SslCtx::init()
{
    return m_internal->init();
}

int32_t SslCtx::uninit()
{
    return m_internal->uninit();
}

int32_t SslCtx::certificate()
{
    return m_internal->certificate();
}

SslConnectionSPtr SslCtx::createConnection()
{
    return SslConnectionInternal::createConnection(m_internal);
}