#include "PracticalSocket.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server host>" << std::endl;
        return 1;
    }

    try
    {
        std::string echoString;
        std::cout << "Enter a message for the server: ";
        std::getline(std::cin >> std::ws, echoString);
        std::cout << std::endl;

        TCPSocket sock(argv[1], 9431);

        uint32_t val = htonl(echoString.length());
        sock.send(&val, sizeof(val));
        sock.send(echoString.c_str(), echoString.length());
        if (sock.recvFully(&val, sizeof(val)) == sizeof(val))
        {
            val = ntohl(val);
            char *buffer = new char[val + 1];
            if (sock.recvFully(buffer, val) == val)
            {
                buffer[val] = '\0';
                std::cout << "Server Response: " << buffer << std::endl;
            }
            delete[] buffer;
        }
    }
    catch (SocketException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}