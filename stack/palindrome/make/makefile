#VARIABLE DECLARATION
CC = gcc
CFLAGS = -c -Wall -g
VFLAGS = --tool=memcheck --leak-check=yes --show-reachable=yes

#DESTINATION
SRC = ../src/
HDRS = ../include/
OBJ = ../obj/
BIN = ../bin/

$(BIN)exe : $(OBJ)main.o $(OBJ)func.o
	$(CC) -o $(BIN)exe $(OBJ)main.o $(OBJ)func.o 

$(OBJ)main.o : $(SRC)main.c $(HDRS)header.h
	$(CC) $(CFLAGS)  $(SRC)main.c -I $(HDRS)
	mv main.o $(OBJ)

$(OBJ)func.o : $(SRC)func.c $(HDRS)header.h
	$(CC) $(CFLAGS)  $(SRC)func.c -I $(HDRS)
	mv func.o $(OBJ)

clean :
	rm $(OBJ)*.o
	rm $(BIN)exe

valgrind : $(BIN)exe $(BIN)input.txt $(BIN)output.txt
	valgrind $(VFLAGS) $(BIN)exe $(BIN)input.txt $(BIN)output.txt
