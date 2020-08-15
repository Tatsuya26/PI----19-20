ficha4.out : ficha_4.o main.o
	gcc -o ficha4.out ficha_4.o main.o

ficha_4.o : ficha_4.c ficha_4.h
	gcc -c ficha_4.c ficha_4.h

main.o : main.c
	gcc -c main.c

clean : 
	rm *.o ficha4.out ficha_4.h.gch