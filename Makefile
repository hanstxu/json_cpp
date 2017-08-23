CXX=g++
CXXOPTIMIZE= -O2
CXXFLAGS= -g -Wall -std=c++0x $(CXXOPTIMIZE)
CLASSES=JSONInterface.h JSONObject.h JSONArray.h JSONObject.cpp JSONArray.cpp

all: main

main: $(CLASSES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $@.cpp

clean:
	rm -rf *.o main