CC = gcc 
CFLAGS = -I inc -O3 
SRC = src/stream.c
OBJ = bin/stream.o
TARGET = run

$(TARGET): $(OBJ)
	$(CC)  main.c $(OBJ) $(CFLAGS) -o $@
	
$(OBJ): $(SRC)
	$(CC) -c $< -o $@



.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET) $(OBJ)/*.o *.exe
