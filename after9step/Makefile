CC=gcc
CFLAGS=-c -Wall -lm
LDFLAGS=-lm
OBJ_DIR=obj

all: practice4

practice4: $(OBJ_DIR)/main.o $(OBJ_DIR)/my_queue.o $(OBJ_DIR)/WIFI.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/my_queue.o $(OBJ_DIR)/WIFI.o $(LDFLAGS) -o practice4

$(OBJ_DIR)/main.o: main.c my_queue.h WIFI.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/my_queue.o: my_queue.c my_queue.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) my_queue.c -o $(OBJ_DIR)/my_queue.o

$(OBJ_DIR)/WIFI.o: WIFI.c WIFI.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) WIFI.c -o $(OBJ_DIR)/WIFI.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) practice4

