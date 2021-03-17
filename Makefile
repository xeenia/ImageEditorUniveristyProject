SOURCES = pro3.c
CFLAG = -c
FLAG = -o
LIBS = -lm
PROGRAM = pro3
FUN = fun.c
OBJECT1 = (SOURCES: .c = .o)
OBJECT2 = (FUN: .c = .o)
CC = gcc
HEAD_M = macros.h
HEAD_S = struct.h
HEAD_F = functions.h
OBJECT = out.o

all :
 	gcc -o pro5 fun.c pro3.c 
#$(PROGRAM) :# $(OBJECT1) $(OBJECT2)
#	$(CC) $(FLAG) $(PROGRAM) pro3.o fun.o

#$(OBJECT) :# $(SOURCES) $(FUN) #$(HEAD_M) $(HEAD_S) $(HEAD_F) 
#	$(CC) $(CFLAG) $(SOURCES) $(FUN) 

#clean:
#	rm *.o $(PROGRAM)