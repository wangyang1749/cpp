
CC=g++
CFLAGS=-g -Wall
LIBS=-lm
OBJ=main.o
$(OBJ):main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ)
TARGET=main

OBJ=Vec2D.o
$(OBJ):Vec2D.cpp
	$(CC) $(CFLAGS) -c Vec2D.cpp -o $(OBJ)
TARGET=main

$(TARGET):main.o Vec2D.o
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)
.PHONY:clean
clean:
    rm $(OBJ) $(TARGET)