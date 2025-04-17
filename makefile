CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic

proj1.x: proj1.cpp
	$(CXX) $(CXXFLAGS) -o proj1.x proj1.cpp


clean:
	rm -f *.o *.x core.*
