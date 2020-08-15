ficha_7.out : ficha_7.o main.o
	gcc -Wall -o ficha7.out ficha_7.o main.o

ficha_7.o : ficha_7.c ficha_7.h
	gcc -Wall -c ficha_7.c ficha_7.h

main.o : main.c
	gcc -Wall -c main.c

clean :
	rm *.o ficha_7.h.gch ficha7.out