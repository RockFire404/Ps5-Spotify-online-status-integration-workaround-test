# Makefile for Prospero (PS5) Toolchain Integration

CC      := x86_64-prospero-gcc
CXX     := x86_64-prospero-g++
CFLAGS  := -O2 -Wall -m64 -fno-builtin

TARGET  := ps5_spotify_test.elf
SRCS    := main.cpp

OBJS    := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "[+] Linking target for PS5 Homebrew Environment..."
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	@echo "[+] Compiling $<..."
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
