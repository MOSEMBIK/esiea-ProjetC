int.out : main.o
	gcc  main.o

main.o : main.c
	gcc  -c   main.c