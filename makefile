# Nom de l'exécutable final
TARGET = cpass

# Fichier source
SRC = cpass.c

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -O2

# Librairies à linker
LIBS = -lssl -lcrypto

# Règle par défaut
all: $(TARGET)

# Comment compiler l'exécutable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Nettoyage des fichiers compilés
clean:
	rm -f $(TARGET)

