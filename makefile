# eenvoudige makefile
all: main.o
	g++ -Wall -g -o Tree main.o
main.o: main.cpp Tree.h
	g++ -Wall -g -c main.cpp