all:
	clear
	bison --yacc --defines --verbose --output=output/parser.c bison/parser.y 
	flex --outfile=output/scanner.c flex/scanner.l
	gcc -o output/greekLex output/scanner.c output/parser.c
	./output/greekLex input/input.txt
	
clean:
	rm output/parser.c output/scanner.c output/parser.output output/parser.h output/greekLex 

