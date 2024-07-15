#!/bin/bash

g++ -c CppFract.c
g++ -c main.c

g++ -o main main.o CppFract.o
rm *.o
