cmake_minimum_required(VERSION 3.25)
project(code_diary)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./leetcode leetcode_src)

add_executable(code_diary ${leetcode_src})
