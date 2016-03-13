CC=g++
CPP=gcc
CFLAGS=-c -Wall -std=c++11 -Iinclude/
LDFLAGS=
# matio compile and linker flags
CFLAGS+=`pkg-config --cflags matio`
LDFLAGS+=`pkg-config --libs  matio`

MATIOCPPSOURCES=src/matio.cpp 
MATIOCPPOBJECTS=$(MATIOCPPSOURCES:.cpp=.o)

TESTSOURCES=src/matiotest.cpp
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)

all: libmatiocpp matiotest

# Build Test
matiotest: $(TESTOBJECTS) 
	$(CC) -L. -lmatiocpp $(TESTOBJECTS) -o $@

#build the shared lib
libmatiocpp: $(MATIOCPPOBJECTS)
	$(CPP) -shared $(MATIOCPPOBJECTS) $(LDFLAGS) -o libmatiocpp.so

# Build o files
.cpp.o:
	$(CC) $(CFLAGS) -fPIC $< -o $@

clean:
	rm *.o src/*.o *.so matiotest
