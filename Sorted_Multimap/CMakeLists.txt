cmake_minimum_required(VERSION 3.21)
project(Sorted_Multimap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sorted_Multimap
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h)
