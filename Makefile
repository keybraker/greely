all:
	clear
	bison --yacc --defines --verbose --output=parser.c bison/parser.y 
	flex --outfile=scanner.c flex/scanner.l
	gcc -o alphac scanner.c parser.c
	./alphac input/input.txt

clean:
	rm parser.c scanner.c parser.output parser.h alphac 

