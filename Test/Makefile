all: Main.exe
	Main.exe

Main.exe: Main.o
	g++ -o $@ $<

Main.o: Main.cpp
	g++ -std=c++11 -c ../toolkit.h
	g++ -std=c++11 -Wall -c $<
