# Simple Makefile for C++

CC = g++ -std=c++11
CFLAGS = -Wall -g
 
# ******************************************************************************
#            Targets needed to bring the executable up to date
# ****************************************************************************** 

OBJ = UseMyTime0.o MyTime0.o

Main : 	$(OBJ)
	$(CC) $(CFLAGS) -o Main $(OBJ)

$(OBJ) : MyTime0.h # This says all .o files need Stock00.h

.PHONY : Clean
Clean:
	rm *.o Main
