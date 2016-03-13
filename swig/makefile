CC=g++
CPP=gcc
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
# matio compile and linker flags
CFLAGS+=`pkg-config --cflags matiocpp`
LDFLAGS+=`pkg-config --libs  matiocpp`

PYCFLAGS=$(CFLAGS) `pkg-config --cflags python`
PYLDFLAGS=$(LDFLAGS) `pkg-config --libs python`

all: pythonlib csharp

csdir:
	mkdir -p csharp
	mkdir -p i_csharp

pydir:
	mkdir -p python
	mkdir -p i_python

#Generate Csharp wrapper
csharp: matio.i csdir
	swig -c++ -outdir i_csharp -o csharp/matio_wrap.cpp -csharp matio.i

python: matio.i pydir
	swig -c++ -outdir i_python -o python/matio_wrap.cpp -python matio.i

#build the shared lib
pythonlib: pythonlib.o
	$(CPP) -shared python/pythonlib.o $(PYLDFLAGS) -o i_python/_matio.so

# Build o files
pythonlib.o: python
	$(CC) $(PYCFLAGS) -fPIC -c python/matio_wrap.cpp -o python/pythonlib.o


clean:
	rm i_csharp/*.cs csharp/*.cpp csharp/*.o i_python/*.py python/*.cpp python/*.o *.so
