cmake_minimum_required(VERSION 3.21)
project(Desing_Patterns)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.56 REQUIRED COMPONENTS iostreams)

include_directories(solid/single_responsibility)

add_subdirectory(builder)

add_executable(Desing_Patterns
    main.cpp
    solid/single_responsibility/single_responsibility.hpp
    solid/open_close/open_close.hpp
    solid/liskov/liskov.hpp
    solid/interface/interface.hpp
    solid/dependency/dependency.hpp
    factory.hpp)
