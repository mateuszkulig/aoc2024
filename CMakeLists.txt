# CMake setup
cmake_minimum_required(VERSION 3.16)
project(aoc_2024 VERSION 1.0.0)

# Includes
include_directories(src)

# Utilities sources
set(aoc_utilities   src/utils/load_file.c)

# Sources
add_executable(day1 src/day1/day1.c ${aoc_utilities})
add_executable(day2 src/day2/day2.c ${aoc_utilities})
