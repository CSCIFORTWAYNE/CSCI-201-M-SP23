all: PracticalSocket.o server client
server: PracticalSocket.o server.cpp
	g++ -pedantic-errors -g server.cpp -o server
client: PracticalSocket.o client.cpp
	g++ -pedantic-errors -g client.cpp -o client
PracticalSocket.o: PracticalSocket.h PracticalSocket.cpp
	g++ -pedantic-errors -g -c PracticalSocket.cpp -o PracticalSocket.o
	