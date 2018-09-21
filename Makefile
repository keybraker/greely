all:
	clear

	bison --yacc --defines --verbose --output=output/parser.c bison_flex/bison/parser.y 
	flex --outfile=output/scanner.c bison_flex/flex/scanner.l
	
	gcc -c output/scanner.c -o output/scanner.o
	gcc -c output/parser.c -o output/parser.o
	gcc -c bison_flex/analyzer/word_exif_data_to_mem.c -o output/word_exif_data_to_mem.o

	gcc -o greely output/scanner.o output/parser.o output/word_exif_data_to_mem.o 

	./greely input/input.txt
	
clean:
	rm output/parser.o output/scanner.o output/word_exif_data_to_mem.o \
	output/parser.c output/scanner.c output/parser.output output/parser.h \
	greely
