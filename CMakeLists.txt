cmake_minimum_required(VERSION 3.18)

project(bio-edu)

add_executable(levenshtein alignment/distance/levenshtein.cpp)
add_executable(pairwise_linear_naive alignment/pairwise/linear_gap_naive.cpp)