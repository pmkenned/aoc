CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++11 -Weffc++ -O2

.PHONY: all part1 part2 clean

all: part1 part2
part1: part1.exe
part2: part2.exe

part1.exe: part1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

part2.exe: part2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.exe *.o
