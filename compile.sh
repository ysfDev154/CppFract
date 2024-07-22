#!/bin/bash

g++ -c CppFract.cpp
g++ -c main.cpp

g++ -o main main.o CppFract.o

#rm *.o
