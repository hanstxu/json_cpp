CXX=g++
CXXOPTIMIZE= -O2
CXXFLAGS= -g -Wall -std=c++0x $(CXXOPTIMIZE)
CLASSES=JSONObject.h JSONArray.h

all: main

main: $(CLASSES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $@.cpp

clean:
	rm -rf *.o main