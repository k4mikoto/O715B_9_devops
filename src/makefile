all: release test

release:
	g++ -c input.cpp
	g++ -c main.cpp
	g++  input.o main.o -o ../usr/bin/devproj9exe
	rm -f input.o 
	rm -f main.o
	
test:
	g++ -c input.cpp
	g++ -c tests.cpp
	g++  input.o tests.o -o ../cicd/testexe
	rm -f input.o 
	rm -f tests.o
