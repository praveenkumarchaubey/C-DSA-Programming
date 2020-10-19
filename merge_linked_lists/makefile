#VARIABLE DECLARATIONS
CC = gcc
CFLAGS = -c -Wall -g
VFLAGS = --tool=memcheck --leak-check=full --show-reachable=yes

#PATH DECLARATIONS
BIN = ./
DATA = ./data/
SRC = ./src/
HDRS = ./include/
OBJ = ./

$(BIN)exe : $(OBJ)main.o $(OBJ)func.o
	$(CC) -o $(BIN)exe $(OBJ)main.o $(OBJ)func.o

$(OBJ)main.o : $(SRC)main.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)main.c -I $(HDRS)

$(OBJ)func.o : $(SRC)func.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)func.c -I $(HDRS)

clean :
	rm $(OBJ)*.o
	rm $(BIN)exe

valgrind : $(BIN)exe $(DATA)input1.txt $(DATA)input2.txt $(DATA)output.txt
	valgrind $(VFLAGS) $(BIN)exe $(DATA)input1.txt $(DATA)input2.txt $(DATA)output.txt

