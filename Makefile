# Executável
TARGET = main

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Diretórios
SRC_DIR = src
INC_DIR = include

# Fontes e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

# Bibliotecas
LIBS = -lraylib -lm -lpthread -ldl -lGL -lrt -lX11

# Flags de include
CFLAGS += -I$(INC_DIR)

# Make
all: $(TARGET)

# Compila o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compila arquivos .c para .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Make run roda o jogo
run: all
	./$(TARGET)

# Make clean remove os arquivos criados
clean:
	rm -f $(OBJ) $(TARGET)