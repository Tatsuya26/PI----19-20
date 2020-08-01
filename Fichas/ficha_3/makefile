ficha3.out : main.o ficha_3.o
	gcc -o ficha3.out main.o ficha_3.o -lm

main.o: main.c 
	gcc -c main.c

ficha_3.o : ficha_3.c ficha_3.h
	gcc -Wall -c ficha_3.c ficha_3.h -lm

clean: 
	rm -f *.o ficha3.out ficha_3.h.gch
