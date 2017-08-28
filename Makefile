CXX=g++
CXXOPTIMIZE= -O2
CXXDEBUG = -g
CXXFLAGS= -Wall -std=c++0x $(CXXOPTIMIZE)
HEADERS=JSONInterface.h JSONObject.h JSONArray.h
CLASSES=JSONObject.cpp JSONArray.cpp

all: libjson example

libjson: $(CLASSES)
	$(CXX) -c $(CXXFLAGS) $^
	ar -cvq $@.a JSONArray.o JSONObject.o
	rm -rf JSONArray.o JSONObject.o

example:
	$(CXX) -o $@ $(CXXFLAGS) $(CXXDEBUG) $@.cpp libjson.a

libClean:
	rm -rf libjson.a
	
exampleClean:
	rm -rf example

clean:
	rm -rf *.o example libjson.a *.h.gch