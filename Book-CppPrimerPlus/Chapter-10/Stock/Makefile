# Simple Makefile for C++

CC = g++
CFLAGS = -Wall -g
 
# ******************************************************************************
#            Targets needed to bring the executable up to date
# ****************************************************************************** 

OBJ = Main.o Stock.o

Main : $(OBJ)
	$(CC) $(CFLAGS) -o Main $(OBJ)

$(OBJ) : Stock00.h # This says all .o files need Stock00.h

.PHONY : Clean
Clean:
	rm *.o Main

# ------------------------------------------------------------------------------
# Below is a raw way of writing Makefile

#Main: Main.o Stock.o
#	$(CC) $(CFLAGS) -o Main Main.o Stock.o
 
# The .o target below doesn't list according .cpp file, which is a default rule.

#Main.o: Stock00.h
#	$(CC) $(CFLAGS) -c Main.cpp
 
#Stock.o: Stock00.h
#	$(CC) $(CFLAGS) -c Stock.cpp

#.PHONY : Clean
#Clean:
#	rm *.o Main
