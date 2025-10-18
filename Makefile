# Executável
TARGET = main

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Caminhos
SRC_DIR = src
INC_DIR = include
RAYLIB_DIR = external/raylib

# Fontes e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

# Bibliotecas
LIBS = -L$(RAYLIB_DIR)/src -lraylib -lm -lpthread -ldl -lGL -lrt -lX11

# Make
all: $(RAYLIB_DIR)/src/libraylib.a $(TARGET)

# Compila Raylib
$(RAYLIB_DIR)/src/libraylib.a:
	@echo ">>> Compilando Raylib..."
	cd $(RAYLIB_DIR)/src && make PLATFORM=PLATFORM_DESKTOP

# Compila seu jogo
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(RAYLIB_DIR)/src -o $@ $^ $(LIBS)

# Compila arquivos .c
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(RAYLIB_DIR)/src -c $< -o $@

# Make run roda o jogo
run: $(TARGET)
	./$(TARGET)

# Make clean limpa os arquivos que ele criou para rodar
clean:
	rm -f $(OBJ) $(TARGET)
	cd $(RAYLIB_DIR)/src && make clean