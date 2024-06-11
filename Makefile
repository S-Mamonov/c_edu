CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
GCOVFLAGS=-fprofile-arcs -ftest-coverage

SOURCES=$(wildcard *.c)
OBJS=$(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $<

all : s21_string.a

s21_string.a : $(OBJS) s21_string.h
	ar rsc s21_string.a $(OBJS)

test : s21_string.a tests.c
	$(CC) $(FLAGS) tests.c s21_string.a -o test -lcheck -lm -lsubunit

gcov_report : s21_string.a tests.c
	$(CC) tests.c s21_string.a -o test -lcheck -lm -lsubunit $(GCOVFLAGS)
	./test
	lcov -t "fizzbuzz" -o rep.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report rep.info --rc lcov_branch_coverage=1

clean :
	rm *.o *.a test *.gc* *.info

rebuild : clean all
