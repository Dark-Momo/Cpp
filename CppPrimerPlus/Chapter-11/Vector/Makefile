# Simple Makefile for C++

CC = g++ -std=c++11
CFLAGS = -Wall -g
 
# ******************************************************************************
#            Targets needed to bring the executable up to date
# ****************************************************************************** 

OBJ = RandomWalk.o Vector.o

Main : 	$(OBJ)
	$(CC) $(CFLAGS) -o Main $(OBJ)

$(OBJ) : Vector.hpp 	# This says all .o files need Vector.h

.PHONY : Clean
Clean:
	rm *.o Main
