CPPFLAGS=-std=c++11 -Wall -pedantic
CC = g++
OBJS = obj/Util.o obj/Process.o obj/P32.o obj/Option.o obj/OptionSim.o obj/OptionClo.o

test : tmp/testp32 tmp/testproc tmp/testutl
clean :
	rm obj/*.o
	rm tmp/*
tmp/testp32 : test/P32test.cpp src/P32.h obj/P32.o obj/Process.o
	$(CC) $(CPPFLAGS) -Isrc -o tmp/testp32 obj/Process.o test/P32test.cpp
tmp/testproc : test/PStest.cpp src/Process.h obj/Process.o
	$(CC) $(CPPFLAGS) -Isrc -o tmp/testproc obj/Process.o test/PStest.cpp
tmp/testutl : test/UFtest.cpp src/Util.h obj/Util.o
	$(CC) $(CPPFLAGS) -Isrc -o tmp/testutl obj/Util.o test/UFtest.cpp
obj/Util.o : src/Util.cpp src/Util.h
	$(CC) $(CPPFLAGS) -c -o obj/Util.o src/Util.cpp 
obj/Process.o : src/Process.cpp src/Process.h
	$(CC) $(CPPFLAGS) -c -o obj/Process.o src/Process.cpp
obj/P32.o : src/P32.cpp src/P32.h
	$(CC) $(CPPFLAGS) -c -o obj/P32.o src/P32.cpp
obj/Option.o : src/Option.cpp src/Option.h
	$(CC) $(CPPFLAGS) -c -o obj/Option.o src/Option.cpp
obj/OptionSim.o : src/OptionSim.cpp src/OptionSim.h
	$(CC) $(CPPFLAGS) -c -o obj/OptionSim.o src/OptionSim.cpp
obj/OptionClo.o : src/OptionClo.cpp src/OptionClo.h
	$(CC) $(CPPFLAGS) -c -o obj/OptionClo.o src/OptionClo.cpp 