cmake_minimum_required(VERSION 3.21)
project(SortedSet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(SortedSet
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedSet.h
        SortedSet.cpp
        SortedSetIterator.cpp
        SortedSetIterator.h
        )