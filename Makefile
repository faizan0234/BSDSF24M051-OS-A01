CC = gcc

CFLAGS = -Wall -Wextra -Iinclude -fPIC

TARGET = bin/client_dynamic

LIB = lib/libmyutils.so

OBJECTS = obj/main.o obj/mystrfunctions.o obj/myfilefunctions.o


all: $(TARGET)


$(LIB): obj/mystrfunctions.o obj/myfilefunctions.o
	$(CC) -shared -o $(LIB) obj/mystrfunctions.o obj/myfilefunctions.o


$(TARGET): obj/main.o $(LIB)
	$(CC) obj/main.o -Llib -lmyutils -o $(TARGET)


obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o


obj/mystrfunctions.o: src/mystrfunctions.c
	$(CC) $(CFLAGS) -c src/mystrfunctions.c -o obj/mystrfunctions.o


obj/myfilefunctions.o: src/myfilefunctions.c
	$(CC) $(CFLAGS) -c src/myfilefunctions.c -o obj/myfilefunctions.o


clean:
	rm -f obj/*.o lib/libmyutils.so bin/client_dynamic
