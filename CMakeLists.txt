cmake_minimum_required(VERSION 3.6)
project(parallel-programming)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fopenmp")
if (MINGW)
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -fopenmp")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -fopenmp -static")
endif (MINGW)

add_subdirectory(src)


