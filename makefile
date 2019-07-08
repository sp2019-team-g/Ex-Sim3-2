CPPFLAGS=-std=c++11 -Wall -pedantic
TESTFLAG=-Isrc -o
CC=g++
TSTS=tmp/testarg tmp/testp32 tmp/testproc tmp/testutl
OBJS=obj/Arguments.o obj/Util.o obj/Process.o obj/P32.o obj/Option.o obj/OptionSim.o obj/OptionClo.o

test : $(TSTS)
clean :
	rm obj/*.o
	rm tmp/*

tmp/testarg : test/ARGtest.cpp src/Arguments.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/ARGtest $(OBJS) test/ARGtest.cpp

tmp/testp32 : test/P32test.cpp $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testp32 $(OBJS) test/P32test.cpp

tmp/testproc : test/PStest.cpp $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testproc $(OBJS) test/PStest.cpp

tmp/testutl : test/UFtest.cpp src/Util.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testutl $(OBJS) test/UFtest.cpp

obj/Arguments.o : src/Arguments.cpp src/Arguments.h
	$(CC) $(CPPFLAGS) -c -o obj/Arguments.o src/Arguments.cpp

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