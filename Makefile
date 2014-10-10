# Homework to The Data Structures and Algorithms - Tampere University of Technology

COMPIL = g++

main: main.o datastructure.o
	$(COMPIL) main.o datastructure.o -o main

datastructure.o: datastructure.cpp datastructure.h
	$(COMPIL) datastructure.cpp -c

main.o: main.cpp
	$(COMPIL) main.cpp -c
