all:
	clear
	bison --yacc --defines --verbose --output=output/parser.c bison_flex/bison/parser.y 
	flex --outfile=output/scanner.c bison_flex/flex/scanner.l
	gcc -o output/greekLex output/scanner.c output/parser.c bison_flex/analyzer_funcs/word_exif_gr.c
	./output/greekLex input/input.txt
	
clean:
	rm output/parser.c output/scanner.c output/parser.output output/parser.h output/greekLex 

