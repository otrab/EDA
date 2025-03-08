CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Primer programa
EXE1 = ejemplo1
SRC1 = ejemplo1.c
OBJ1 = $(SRC1:.c=.o)

# Segundo programa
EXE2 = ejemplo2
SRC2 = ejemplo2.c
OBJ2 = $(SRC2:.c=.o)

all: $(EXE1) $(EXE2)

$(EXE1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJ1)

$(EXE2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJ2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) $(EXE1) $(EXE2)

.PHONY: all clean