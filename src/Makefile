CFLAGS=-Wall -Wextra -Werror -std=c11
GCOV=-fprofile-arcs -ftest-coverage -fPIC
FILES=\
	s21_strlen.c s21_strcmp.c s21_strchr.c s21_sprintf.c\
	s21_sscanf.c s21_itoa.c s21_atoi.c s21_ftoa.c s21_utoa.c\
	s21_strcat.c s21_otoa.c s21_xtoa.c spec_g.c\
	s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c\
	s21_memset.c s21_strerror.c s21_strncpy.c s21_strncmp.c\
	s21_strpbrk.c s21_strspn.c s21_strstr.c s21_strtok.c\
	s21_trim.c s21_to_upper.c s21_to_lower.c s21_strrchr.c\
	s21_strncat.c s21_strcspn.c s21_strcpy.c s21_insert.c s21_my_itoa.c
OS=$(shell uname)

all: s21_string.a

gcov_report: test
	lcov -t "string_h" -o string_h.info -c -d .
	genhtml -o report string_h.info
ifeq (${OS}, Linux)
		cd report && firefox index.html
else
		cd report && open index.html
endif

test: 
	gcc s21_string_test.c -c
	gcc ${GCOV} ${CFLAGS} -lcheck -pthread -lm -L. ${FILES} s21_string_test.o
	./a.out

s21_string.a: s21_string.o
	ar rc libs21_string.a *.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.a

s21_string.o: ${FILES}
	gcc ${CFLAGS} -c ${FILES}

.PHONY: all build clean rebuild

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a test *.css *.html vgcore* main report *.info *.gz *.log

rebuild: clean s21_string.a

rebuild_test: clean test