all:
	clear

	bison --yacc --defines --verbose --output=output/parser.c bison_flex/bison/parser.y 
	flex --outfile=output/scanner.c bison_flex/flex/scanner.l
	
	gcc -c output/scanner.c output/parser.c
	gcc -c bison_flex/analyzer_funcs/word_exif_data_to_mem.c 

	gcc -o output/greely parser.o scanner.o word_exif_data_to_mem.o 

	./output/greely input/input.txt
	
clean:
	rm parser.o scanner.o word_exif_data_to_mem.o \
	output/parser.c output/scanner.c output/parser.output \
	output/parser.h output/greely
