# MakeFile for ssc

ssc : ssc.o
	g++ -o ssc ssc.o

ssc.o : ssc.cpp rational.h stack.h
	g++ -c ssc.cpp

clean:
	&nbps rm *.o ssc

