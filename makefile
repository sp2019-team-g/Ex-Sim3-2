CPPFLAGS=-std=c++11 -Wall -pedantic
CC = g++

testutl : test/UFtest.cpp src/Util.h obj/Util.o
	$(CC) $(CPPFLAGS) -Isrc -o testutl obj/Util.o  test/UFtest.cpp
obj/Util.o : src/Util.cpp src/Util.h
	$(CC) $(CPPFLAGS) -c -o obj/Util.o src/Util.cpp 

