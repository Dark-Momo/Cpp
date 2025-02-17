# Simple Makefile for C++

CC = g++ -std=c++11
CFLAGS = -Wall -g
 
# ******************************************************************************
#            Targets needed to bring the executable up to date
# ****************************************************************************** 

OBJ = UsingTest.o StringTest.o

Main : 	$(OBJ)
	$(CC) $(CFLAGS) -o Main $(OBJ)

$(OBJ) : StringTest.hpp 	# This says all .o files need this .hpp

.PHONY : Clean
Clean:
	rm *.o Main
