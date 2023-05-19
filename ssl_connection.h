#ifndef SSL_CONNECTION_H
#define SSL_CONNECTION_H

#include <memory>
#include <WinSock2.h>

class SslConnectionInternal;

class SslConnection
{
public:
    int32_t setFd(SOCKET fd);

    int32_t handshake();

    int32_t shutdown();

    int32_t send(const uint8_t* buf, size_t len);

    int32_t recv(uint8_t* buf, size_t len);

private:
    SslConnection();

    ~SslConnection();

private:
    friend class SslConnectionInternal;
    std::unique_ptr<SslConnectionInternal> m_internal;
};

using SslConnectionSPtr = std::shared_ptr<SslConnection>;

#endif
