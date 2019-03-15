//CPPFLAGS = -Wall -g -std=c++11

all: martian

martian: weatherlog.o datalogger.o linkedlist.o
	g++ weatherlog.o datalogger.o linkedlist.o -o martian

weatherlog.o: weatherlog.cpp
	g++ -g -c weatherlog.cpp

datalogger.o: datalogger.cpp
	g++ -g -c datalogger.cpp

linkedlist.o: linkedlist.cpp
	g++ -g -c linkedlist.cpp

clean:
	rm *.o ./martian
