# Nombre del ejecutable final
TARGET = programa

# Compilador y banderas
CC = gcc
CFLAGS = -Iheaders -Wall

# Localización de archivos fuente
# Buscamos main.c en raíz y funciones.c en la carpeta code
SRCS = main.c code/funciones.c

# Generar nombres de archivos objeto (.o)
OBJS = $(SRCS:.c=.o)

# Regla principal: Compilar el programa
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regla para archivos objeto (indica que dependen de los .h)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos temporales
clean:
	rm -f $(OBJS) $(TARGET)
