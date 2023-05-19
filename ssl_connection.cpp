#include "ssl_connection.h"
#include "ssl_connection_impl.h"

SslConnection::SslConnection()
{

}

SslConnection::~SslConnection()
{

}

int32_t SslConnection::setFd(SOCKET fd)
{
    return m_internal->setFd(fd);
}

int32_t SslConnection::handshake()
{
    return m_internal->handshake();
}

int32_t SslConnection::shutdown()
{
    return m_internal->shutdown();
}

int32_t SslConnection::send(const uint8_t* buf, size_t len)
{
    return m_internal->send(buf, len);
}

int32_t SslConnection::recv(uint8_t* buf, size_t len)
{
    return m_internal->recv(buf, len);
}