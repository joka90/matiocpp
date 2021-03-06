cmake_minimum_required(VERSION 2.8)

project (matiocpp)
set(matiocpp_VERSION_MAJOR 0)
set(matiocpp_VERSION_MINOR 1)

set(CMAKE_BUILD_TYPE Release)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(matiocpp SHARED src/matio.cpp)
TARGET_LINK_LIBRARIES(matiocpp matio)

add_executable(matiotest src/matiotest.cpp)
TARGET_LINK_LIBRARIES(matiotest matiocpp)


SET(PKG_CONFIG_REQUIRES matio)
SET(PKG_CONFIG_LIBDIR "\${prefix}/lib")
SET(PKG_CONFIG_INCLUDEDIR "\${prefix}/include/matiocpp")
SET(PKG_CONFIG_LIBS "-L\${libdir} -lmatiocpp" )
SET(PKG_CONFIG_CFLAGS "-I\${includedir}" )


CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/matiocpp.pc.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
)

INSTALL(TARGETS matiocpp DESTINATION "lib")
INSTALL(FILES include/matio.hpp DESTINATION "../include/matiocpp")
INSTALL(FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc" DESTINATION "lib/pkgconfig/")


