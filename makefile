CC = cc
Cperf = -O3
CFlags = -Wall -Wextra -pedantic -Wnonnull

make_tests:
	$(CC) $(Cperf) -o test ./tests/test.c -L. -lsstr

make_examples:
	$(CC) $(Cperf) -o example ./examples/main.c -L. -lsstr 

run:
	$(CC) -o -Wall -Wextra -Werror -Wnonnull main sstr.c && ./main

comp:
	$(CC) -o main -Wall -Wextra -Werror -Wnonnull sstr.c

make_linux:
	$(CC) -c ./src/sstr.c -o sstr.o
	ar rcs libsstr.a sstr.o 
	rm -rf ./sstr.o 
