CXX= g++

all: clean ks.exe

.cpp.o:
	$(CXX) -c -g -O0 -o $@ $<  -std=c++11

ks.exe: ks.o
	$(CXX) -o ks.exe ks.o -std=c++11

clean:
	rm -f *.o *~ \#*\# ks.exe