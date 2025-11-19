# Executável
TARGET = main

# Compilador e flags
CFLAGS = -Wall -Wextra -O2

# Diretórios
SRC_DIR = src
INC_DIR = include

# Fontes e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

# Detecção do Sistema Operacional
ifeq ($(OS),Windows_NT)
    # Windows
    TARGET := $(TARGET).exe
    CC = C:/raylib/w64devkit/bin/gcc.exe
    RAYLIB_PATH = C:/raylib/raylib-5.0_win64_mingw-w64
    LIBS = -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm
    RAYLIB_INCLUDE = -I$(RAYLIB_PATH)/include
else
    # Linux
    CC = gcc
    LIBS = -lraylib -lm -lpthread -ldl
    RAYLIB_INCLUDE = -I/usr/local/include
endif

# Flags de include
CFLAGS += -I$(INC_DIR) $(RAYLIB_INCLUDE)

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

.PHONY: all run clean