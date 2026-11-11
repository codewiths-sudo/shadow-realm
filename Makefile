CC = gcc
CFLAGS = -Wall -g
TARGET = main

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
    EXT = .exe
else
    RM = rm -f
    EXT =
endif

all: $(TARGET)$(EXT)

$(TARGET)$(EXT): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)$(EXT)

clean:
	-$(RM) $(TARGET)$(EXT)