#VARIABLE DECLARATIONS
CC = gcc
CFLAGS = -c -Wall -g
VFLAGS = --tool=memcheck --leak-check=full --show-reachable=yes

#PATH DECLARATIONS
DATA = ./data/
SRC = ./src/
HDRS = ./include/

exe : main.o func.o
	$(CC) -o exe main.o func.o

main.o : $(SRC)main.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)main.c -I $(HDRS)

func.o : $(SRC)func.c $(HDRS)header.h
	$(CC) $(CFLAGS) $(SRC)func.c -I $(HDRS)

clean :
	rm *.o
	rm exe

valgrind : exe $(DATA)input.txt $(DATA)output.txt
	valgrind $(VFLAGS) exe "praveen chaubey" "sandeep chaubey" "pradeep chaubey" "mini samal" "varsha" $(DATA)output.txt

