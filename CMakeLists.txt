cmake_minimum_required(VERSION 3.17)
project(Schnorr)

set(CMAKE_CXX_STANDARD 14)

add_executable(Schnorr main.cpp verifier.cpp verifier.h prover.cpp prover.h fun.cpp fun.h view.cpp view.h)