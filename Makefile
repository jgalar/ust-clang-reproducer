CXX=clang++
CXXFLAGS=-std=c++11 -I. -Wall -g -O -fPIC

.PHONY: all clean

all: mylib.so myproviders.so myapp.exe

clean:
	rm -f *.o *.so *.exe

mylib.so: mylib.o
	$(LINK.cpp) -ldl -shared -fpic $^ -o $@

mylib.o: mylib.cpp

myproviders.so: providers.cpp
	$(LINK.cpp) -shared -fpic -llttng-ust $^ -o $@

myapp.exe: myapp.cpp
	$(CC) $^ -ldl -o myapp.exe
