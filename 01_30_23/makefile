all: clockType clockExcept
	g++ -pedantic-errors -g main.cpp clockType clockExcept -o main
clockType: clockType.h clockType.cpp
	g++ -pedantic-errors -g -c clockType.cpp -o clockType
clockExcept: clockExcept.h clockExcept.cpp
	g++ -pedantic-errors -g -c clockExcept.cpp -o clockExcept