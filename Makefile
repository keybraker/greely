#rm database [obsolete]/newGreekNameDatabase.txt
all:
	clear
	bison --yacc --defines --verbose --output=output/parser.c bison/parser.y 
	flex --outfile=output/scanner.c flex/scanner.l
	gcc -o output/greekLex output/scanner.c output/parser.c wordExif/wordExifGr.c
	./output/greekLex input/input.txt
	
clean:
	rm output/parser.c output/scanner.c output/parser.output output/parser.h output/greekLex 

