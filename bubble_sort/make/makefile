#VARIABLE DECLARATIONS
CC = gcc
CFLAGS = -c -Wall -g
VFLAGS = --tool=memcheck --leak-check=full --show-reachable=yes

#PATH DECLARATIONS
BIN = ../bin/
HDRS = ../include/
OBJ = ../obj/
SRC = ../src/

$(BIN)exe : $(OBJ)main.o $(OBJ)func.o
	$(CC) -o $(BIN)exe $(OBJ)main.o $(OBJ)func.o

$(OBJ)main.o : $(SRC)main.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)main.c -I $(HDRS)
	mv main.o $(OBJ)

$(OBJ)func.o : $(SRC)func.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)func.c -I $(HDRS)
	mv func.o $(OBJ)

clean :
	rm $(OBJ)*.o
	rm $(BIN)exe

valgrind : $(BIN)exe $(BIN)input1.txt $(BIN)input2.txt $(BIN)output.txt
	valgrind $(VFLAGS) $(BIN)exe $(BIN)input1.txt $(BIN)input2.txt $(BIN)output.txt

