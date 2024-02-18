all:
	gcc -Wall -Werror -g -Wextra -pedantic -std=gnu89 *.c -o hsh

leak:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./hsh

betty:
	betty shell.h *.c
