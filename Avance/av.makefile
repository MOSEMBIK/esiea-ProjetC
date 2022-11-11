av.out : main.o struct.o
	gcc  main.o struct.o

main.o : main.c struct.h
	gcc  -c   main.c

struct.o : struct.c struct.h
	gcc  -c   struct.c