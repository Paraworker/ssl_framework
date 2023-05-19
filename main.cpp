#include "defs.h"
#include "ssl_ctx.h"
#include <iostream>

int main()
{
    // server ctx
    SslCtx serverCtx(false);

    if (serverCtx.init() != ERROR_NO)
    {
        std::cout << "serverCtx init failed" << std::endl;
        return -1;
    }

    // server certificate
    if (serverCtx.certificate() != ERROR_NO)
    {
        std::cout << "serverCtx certificate failed" << std::endl;
        return -1;
    }

    // server createConnection
    auto serverCon = serverCtx.createConnection();

    // serverCon setFd
    if (serverCon->setFd() != ERROR_NO)
    {
        std::cout << "serverCon setFd failed" << std::endl;
        return -1;
    }



    return 0;
}
