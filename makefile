# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
SRC = main.c double_list.c

# Regla 1, para compilar el programa principal
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regla 2, para limpiar archivos generados
clean:
	rm -f $(TARGET)
