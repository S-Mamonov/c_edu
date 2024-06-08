CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11

SOURCES=$(wildcard *.c)
OBJS=$(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $<

all : s21_string.a

s21_string.a : $(OBJS) s21_string.h
	ar rsc s21_string.a $(OBJS)

clean :
	rm *.o *.a

rebuild : clean all
