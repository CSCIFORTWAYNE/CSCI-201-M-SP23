#include "PracticalSocket.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server host>" << std::endl;
        return 1;
    }

    try
    {
        std::cout << argv[1] << std::endl;
        TCPSocket sock(argv[1], 9431);
        int input;
        std::cout << "Enter the starting number: ";
        std::cin >> input;
        while (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Enter the starting number: ";
            std::cin >> input;
        }
        uint32_t val = static_cast<uint32_t>(input); // = atoi(argv[2]);
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