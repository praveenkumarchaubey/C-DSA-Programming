#VARIABLE DECLARATION
CC = gcc
CFLAGS = -c -Wall -g
VFLAGS = --tool=memcheck --leak-check=full --show-reachable=yes

#DESTINATION
SRC = src/
HDRS = include/
OBJ = ./
BIN = ./

$(BIN)exe : $(OBJ)main.o $(OBJ)func.o
	$(CC) -o $(BIN)exe $(OBJ)main.o $(OBJ)func.o 

$(OBJ)main.o : $(SRC)main.c $(HDRS)header.h
	$(CC) $(CFLAGS)  $(SRC)main.c -I $(HDRS)

$(OBJ)func.o : $(SRC)func.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)func.c -I $(HDRS)

clean :
	rm $(OBJ)*.o
	rm $(BIN)exe

valgrind : $(BIN)exe
	valgrind $(VFLAGS) $(BIN)exe
