# Homework to The Data Structures and Algorithms - Tampere University of Technology

COMPIL = g++

main: main.o datastructure.o
	$(COMPIL) main.o datastructure.o -o main -std=c++11

datastructure.o: datastructure.cpp datastructure.h
	$(COMPIL) datastructure.cpp -c -std=c++11

main.o: main.cpp
	$(COMPIL) main.cpp -c -std=c++11
clean:
	rm main
	rm *.o
