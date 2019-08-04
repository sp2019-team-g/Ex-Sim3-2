CPPFLAGS=-std=c++11 -Wall -pedantic
TESTFLAG=-Isrc -o
CC=g++
TSTS1=tmp/testarg tmp/testp32 tmp/testproc tmp/testutl tmp/testopt tmp/testeuc tmp/testinp tmp/testfac
TSTS2=tmp/testbes tmp/testrv
TSTS=$(TSTS1) $(TSTS2)
OBJS1=obj/Arguments.o obj/Util.o obj/Process.o obj/Option.o obj/Input.o obj/Factory.o
OBJS2=obj/PGBM.o obj/PricingEng.o obj/McPricingEng.o obj/EUCallOpt.o obj/EUPutOpt.o obj/P32.o
OBJS3=obj/rv_library.o obj/BES.o obj/EUBarrierUpOutCallOpt.o obj/EUBarrierUpOutPutOpt.o obj/ASPutOpt.o obj/ASCallOpt.o
OBJS=$(OBJS1) $(OBJS2) $(OBJS3)
test : $(TSTS)
clean :
	rm obj/*.o
	rm tmp/*
	rm bin/*

bin/app : src/app.cpp $(OBJS)
	$(CC) $(CPPFLAGS) -Isrc -o bin/app src/app.cpp $(OBJS)

tmp/testopt : test/OPTtest.cpp src/Option.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testopt $(OBJS) test/OPTtest.cpp

tmp/testarg : test/ARGtest.cpp src/Arguments.h $(OBJS)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testarg $(OBJS) test/ARGtest.cpp

tmp/testp32 : test/P32test.cpp $(OBJS) $(OBJBSI)
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testp32 $(OBJS) $(OBJBSI) test/P32test.cpp

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

tmp/testbsi : test/BSItest.cpp src/Besseli.h obj/Besseli.o
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testbsi obj/Besseli.o test/BSItest.cpp

tmp/testrv : test/RVtest.cpp src/rv_library.h obj/rv_library.o
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testrv obj/rv_library.o test/RVtest.cpp

tmp/testbes : test/BEStest.cpp src/BES.h obj/BES.o
	$(CC) $(CPPFLAGS) $(TESTFLAG) tmp/testbes obj/BES.o test/BEStest.cpp

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

obj/ASCallOpt.o : src/ASCallOpt.cpp src/ASCallOpt.h
	$(CC) $(CPPFLAGS) -c -o obj/ASCallOpt.o src/ASCallOpt.cpp

obj/ASPutOpt.o : src/ASPutOpt.cpp src/ASPutOpt.h
	$(CC) $(CPPFLAGS) -c -o obj/ASPutOpt.o src/ASPutOpt.cpp

obj/EUBarrierUpOutCallOpt.o : src/EUBarrierUpOutCallOpt.cpp src/EUBarrierUpOutCallOpt.h
	$(CC) $(CPPFLAGS) -c -o obj/EUBarrierUpOutCallOpt.o src/EUBarrierUpOutCallOpt.cpp

obj/EUBarrierUpOutPutOpt.o : src/EUBarrierUpOutPutOpt.cpp src/EUBarrierUpOutPutOpt.h
	$(CC) $(CPPFLAGS) -c -o obj/EUBarrierUpOutPutOpt.o src/EUBarrierUpOutPutOpt.cpp

obj/PricingEng.o : src/PricingEng.cpp src/PricingEng.h
	$(CC) $(CPPFLAGS) -c -o obj/PricingEng.o src/PricingEng.cpp

obj/McPricingEng.o : src/McPricingEng.cpp src/McPricingEng.h
	$(CC) $(CPPFLAGS) -c -o obj/McPricingEng.o src/McPricingEng.cpp

obj/Input.o : src/Input.cpp src/Input.h
	$(CC) $(CPPFLAGS) -c -o obj/Input.o src/Input.cpp

obj/Factory.o : src/Factory.cpp src/Factory.h
	$(CC) $(CPPFLAGS) -c -o obj/Factory.o src/Factory.cpp

obj/rv_library.o : src/rv_library.cpp src/rv_library.h
	$(CC) $(CPPFLAGS) -c -o obj/rv_library.o src/rv_library.cpp

obj/BES.o : src/BES.cpp src/BES.h
	$(CC) $(CPPFLAGS) -c -o obj/BES.o src/BES.cpp

