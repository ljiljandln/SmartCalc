CFLAGS = -Wall -Werror -Wextra -std=c11
CC = gcc
CHECK_FLAGS = $(shell pkg-config --cflags --libs check)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -fPIC
LIBRARY = s21_smartcalc.a

SRC= $(wildcard *.c)
OBJ = $(patsubst %.c,%.o, ${SRC})
SRC_TEST = $(wildcard tests/*.c)
OBJ_TEST = test.o

all: s21_smart_calc.a test gcov_report

$(LIBRARY): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(LIBRARY) $(OBJ)
	rm $(OBJ)

test: $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(CHECK_FLAGS)
	./test

$(OBJ_TEST):
	$(CC) -c $(SRC_TEST)

gcov_report: clean $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC) $(CHECK_FLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	make open

rebuild: clean test

open: 
	open report/index.html

.PHONY: all clean rebuild open clang install install_first open_calc uninstall

clean:
	rm -rf *.o test *.a tests/*.o *.gcda *.gcno report *.info

clang:
	clang-format --style=google -i $(SRC)

install: install_first
	chmod 777 ./build/smartCalc1.app
	open ./build/smartCalc1.app

install_first:
	mkdir build
	cd build/ && qmake ../smartCalc1.pro && make

open_calc:
	open ./build/smartCalc1.app

uninstall:
	@-rm -rf build/
	@-rm -rf *.tgz

dist: 
	mkdir build
	cd build/ && qmake ../smartCalc1.pro && make
	tar cvzf dist_smartCalc1.tgz build/

dvi:
	open readme.txt