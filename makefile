CFLAGS := -std=gnu99 -ffreestanding -nostdlib -O0 -Wall -fpie 
CC := $(HOME)/opt/cross/bin/i686-elf-gcc

PROJDIRS := $(shell pwd)
SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c")
ASMFILES := $(shell find $(PROJDIRS) -type f -name "*.asm")
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES)) $(patsubst %.asm,%.o,$(ASMFILES))
DEPFILES := $(patsubst %.o,%.d,$(OBJFILES))

.PHONY: clean compile all

-include $(DEPFILES)

all: clean compile
	@echo all

clean:
	@echo cleaning
	rm -f *.o *.elf

compile: hello.elf bg_proc.elf
	@echo compiling

hello.elf: makefile syscalls.o syscall.o  hello.o
	$(CC) $(CFLAGS) -static -pie -e main -o $@ syscalls.o syscall.o hello.o
	
bg_proc.elf: makefile syscalls.o syscall.o sleep_test.o
	$(CC) $(CFLAGS)  -static -pie -e main -o $@ syscalls.o syscall.o sleep_test.o

%.o: %.c makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

%.o: %.asm makefile 
	nasm -felf32 $< -o $@
