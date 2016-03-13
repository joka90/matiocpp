#libmatiocpp
Working but it's really rough and nothing to trust.

The makefile will build the wrapper lib and a test binary.

## Build matiocpp
`
cmake .
`

`
make
`

`
sudo make install
`

## Build and install matio
Download libmatio and unpack.
You may need to install additional libs and compile hdf for mat73 support.
### Fedora 22
`
./configure --libdir=/usr/lib64 --includedir=/usr/include/libmatio
`

`
make
`

`
sudo make install
`

## TODO
* Better input structures. Using standard C types right now. Maybe use the new array type?
* Operator overloading of [] or (), the problem with this is whom is responsible for the memory
* Figure out a way to better keep track of the memory. (The wrapped matio pointers)
