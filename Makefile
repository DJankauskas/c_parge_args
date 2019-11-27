all: main.c
	gcc -o parse_args.out main.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o

run: 
	./parse_args.out