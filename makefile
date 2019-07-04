CPPFLAGS=-std=c++11 -Wall -pedantic
CC = g++

testproc : test/PStest.cpp src/Process.h obj/Process.o
	$(CC) $(CPPFLAGS) -Isrc -o testproc obj/Process.o test/PStest.cpp
testutl : test/UFtest.cpp src/Util.h obj/Util.o
	$(CC) $(CPPFLAGS) -Isrc -o testutl obj/Util.o  test/UFtest.cpp
obj/Util.o : src/Util.cpp src/Util.h
	$(CC) $(CPPFLAGS) -c -o obj/Util.o src/Util.cpp 
obj/Process.o : src/Process.cpp src/Process.h
	$(CC) $(CPPFLAGS) -c -o obj/Process.o src/Process.cpp

