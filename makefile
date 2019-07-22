CPPFLAGS=-std=c++11 -Wall -pedantic
TESTFLAG=-Isrc -o
CC=g++
TSTS=tmp/testarg tmp/testp32 tmp/testproc tmp/testutl tmp/testopt tmp/testeuc tmp/testinp tmp/testfac
OBJS1=obj/Arguments.o obj/Util.o obj/Process.o obj/P32.o obj/Option.o obj/Input.o obj/Factory.o
OBJS2=obj/PGBM.o obj/PricingEng.o obj/McPricingEng.o obj/EUCallOpt.o obj/EUPutOpt.o
OBJS=$(OBJS1) $(OBJS2)
test : $(TSTS)
clean :
	rm obj/*.o
	rm tmp/*

tmp/testopt : test/OPTtest.cpp src/Option.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testopt $(OBJS) test/OPTtest.cpp

tmp/testarg : test/ARGtest.cpp src/Arguments.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testarg $(OBJS) test/ARGtest.cpp

tmp/testp32 : test/P32test.cpp $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testp32 $(OBJS) test/P32test.cpp

tmp/testproc : test/PStest.cpp $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testproc $(OBJS) test/PStest.cpp

tmp/testutl : test/UFtest.cpp src/Util.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testutl $(OBJS) test/UFtest.cpp

tmp/testeuc : test/EUOtest.cpp src/EUCallOpt.h src/EUPutOpt.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testeuc $(OBJS) test/EUOtest.cpp

tmp/testinp : test/INPtest.cpp src/Input.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testinp $(OBJS) test/INPtest.cpp

tmp/testfac : test/FACtest.cpp src/Factory.h src/PGBM.h src/EUCallOpt.h src/McPricingEng.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testfac $(OBJS) test/FACtest.cpp

obj/Arguments.o : src/Arguments.cpp src/Arguments.h
	$(CC) $(CPPFLAGS) -c -o obj/Arguments.o src/Arguments.cpp

obj/Util.o : src/Util.cpp src/Util.h
	$(CC) $(CPPFLAGS) -c -o obj/Util.o src/Util.cpp 

obj/Process.o : src/Process.cpp src/Process.h
	$(CC) $(CPPFLAGS) -c -o obj/Process.o src/Process.cpp

obj/PGBM.o : src/PGBM.cpp src/PGBM.h
	$(CC) $(CPPFLAGS) -c -o obj/PGBM.o src/PGBM.cpp

obj/P32.o : src/P32.cpp src/P32.h
	$(CC) $(CPPFLAGS) -c -o obj/P32.o src/P32.cpp

obj/Option.o : src/Option.cpp src/Option.h
	$(CC) $(CPPFLAGS) -c -o obj/Option.o src/Option.cpp

obj/EUCallOpt.o : src/EUCallOpt.cpp src/EUCallOpt.h
	$(CC) $(CPPFLAGS) -c -o obj/EUCallOpt.o src/EUCallOpt.cpp

obj/EUPutOpt.o : src/EUPutOpt.cpp src/EUPutOpt.h
	$(CC) $(CPPFLAGS) -c -o obj/EUPutOpt.o src/EUPutOpt.cpp

obj/PricingEng.o : src/PricingEng.cpp src/PricingEng.h
	$(CC) $(CPPFLAGS) -c -o obj/PricingEng.o src/PricingEng.cpp

obj/McPricingEng.o : src/McPricingEng.cpp src/McPricingEng.h
	$(CC) $(CPPFLAGS) -c -o obj/McPricingEng.o src/McPricingEng.cpp

obj/Input.o : src/Input.cpp src/Input.h
	$(CC) $(CPPFLAGS) -c -o obj/Input.o src/Input.cpp

obj/Factory.o : src/Factory.cpp src/Factory.h
	$(CC) $(CPPFLAGS) -c -o obj/Factory.o src/Factory.cpp


