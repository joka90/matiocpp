#libmatiocpp
Not working currently. This is just a initial skeleton for the wrapper.

The makefile will build the wrapper lib and a test binary.

## Build matiocpp
`make`

## Build and install matio
Download libmatio and unpack.
You may need to install additional libs and compile hdf for mat73 support.
### Fedora 22
`./configure --libdir=/usr/lib64 --includedir=/usr/include/libmatio`
`make`
`make install`

### TODO 