main: main.cpp
	g++ -std=c++11 main.cpp -o main
debugged: main.cpp
	g++ -std=c++11 main.cpp -o debugged -g