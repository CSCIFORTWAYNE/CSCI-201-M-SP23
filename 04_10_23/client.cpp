#include "PracticalSocket.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: ./client <server host> <starting value>" << std::endl;
        return 1;
    }

    try
    {
        std::cout << argv[1] << std::endl;
        TCPSocket sock(argv[1], 9431);
        uint32_t val = atoi(argv[2]);
        val = ntohl(val);
        sock.send(&val, sizeof(val));
        if (sock.recvFully(&val, sizeof(val)) == sizeof(val))
        {
            val = ntohl(val);
            std::cout << "Server Response: " << val << std::endl;
        }
    }
    catch (SocketException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}