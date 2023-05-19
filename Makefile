CC = g++
CFLAGS = -Wall -O2

TARGET= run
SOURCE = src/hello.c 
OBJECT = $(patsubst %.c, %.o, $(SOURCE))


all: $(TARGET)

$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) -o bin/$@ $^


src/%.o :%.c 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f bin/$(TARGET) src/*.o