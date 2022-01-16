cmake_minimum_required(VERSION 3.21)
project(trans_gene_locus_finder)

set(CMAKE_CXX_STANDARD 14)


add_executable(trans_gene_locus_finder main.cpp threads_code.cpp threads_code.h)
add_subdirectory(zlib)

target_link_libraries(${PROJECT_NAME} zlib)