CC=g++
CPP=gcc
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
# matio compile and linker flags
CFLAGS+=`pkg-config --cflags matiocpp`
LDFLAGS+=`pkg-config --libs  matiocpp`

PYCFLAGS=$(CFLAGS) `pkg-config --cflags python`
PYLDFLAGS=$(LDFLAGS) `pkg-config --libs python`

CSCFLAGS=$(CFLAGS) `pkg-config --cflags mono-2`
CSLDFLAGS=$(LDFLAGS) `pkg-config --libs mono-2`

all: pythonlib csharpdll

csdir:
	mkdir -p csharp
	mkdir -p i_csharp

pydir:
	mkdir -p python
	mkdir -p i_python

#Generate Csharp wrapper
csharp: matio.i csdir
	swig -c++ -namespace matio -outdir i_csharp -o csharp/matio_wrap.cpp -csharp matio.i

#build the shared lib
csharplib: csharplib.o
	$(CPP) -shared csharp/csharplib.o $(CSLDFLAGS) -o i_csharp/_matio.so

# Build o files
csharplib.o: csharp
	$(CC) $(CSCFLAGS) -fPIC -c csharp/matio_wrap.cpp -o csharp/csharplib.o

#build dll
csharpdll: csharplib
	xbuild i_csharp/matio.csproj

#Generate python wrapper
python: matio.i pydir
	swig -c++ -outdir i_python -o python/matio_wrap.cpp -python matio.i

#build the shared lib
pythonlib: pythonlib.o
	$(CPP) -shared python/pythonlib.o $(PYLDFLAGS) -o i_python/_matio.so

# Build o files
pythonlib.o: python
	$(CC) $(PYCFLAGS) -fPIC -c python/matio_wrap.cpp -o python/pythonlib.o


clean:
	rm i_csharp/*.cs csharp/*.cpp csharp/*.o i_python/matio.py python/*.cpp python/*.o i_python/*.so i_csharp/*.so i_csharp/bin/Debug/matio.dll
