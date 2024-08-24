all: prog

prog: curse_work.o 
	gcc -o prog curse_work.o

main.o: curse_work.c 
	gcc -c curse_work.c 

clean:
	rm curse_work.o prog