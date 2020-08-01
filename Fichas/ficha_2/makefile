ficha2.out : ficha_2.o main.o
	gcc -o ficha2.out ficha_2.o main.o

ficha_2.o : ficha_2.c ficha_2.h
	gcc -c ficha_2.c ficha_2.h

main.o :
	gcc -c main.c

clean: 
	rm *.o ficha_2.h.gch ficha2.out