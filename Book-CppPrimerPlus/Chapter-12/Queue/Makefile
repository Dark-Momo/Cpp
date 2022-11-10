# Simple Makefile for C++

CC = g++ -std=c++11
CFLAGS = -Wall -g
 
# ******************************************************************************
#            Targets needed to bring the executable up to date
# ****************************************************************************** 

OBJ = Queue.o QueueSim.o

Main : 	$(OBJ)
	$(CC) $(CFLAGS) -o Main $(OBJ)

$(OBJ) : Queue.hpp 	# This says all .o files need this .hpp

.PHONY : Clean
Clean:
	rm *.o Main
