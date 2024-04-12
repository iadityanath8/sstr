CC = cc
CFlags = -Wall -Wextra -Wnonnull -pedantic 
ccheck = valgrind

run:
	$(CC) $(CFlags) -o main sstr.c && ./main

comp:
	$(CC) $(CFlags) -o main testsstr.c

check:
	$(ccheck) ./main

clean:
	rm -rf ./main
