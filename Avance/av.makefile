av.out : main.o struct.o
	gcc  main.o struct.o

main.o : main.c struct.h
	gcc  -c   main.c

struct.o : struct.h struct.c
	gcc  -c   struct.c