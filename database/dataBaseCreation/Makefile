1:
	gcc -o generateDatabases wordsToDatabases.c
	./generateDatabases

2:
	gcc -o generateVerbs verbsCreator.c verbCreatingFunctions/functionsForXronous.c verbCreatingFunctions/enestotas.c verbCreatingFunctions/paratatikos.c verbCreatingFunctions/aoristos.c verbCreatingFunctions/eksakolouthitikos_mellontas.c verbCreatingFunctions/stigmiaios_mellontas.c verbCreatingFunctions/suntelesmenos_mellontas.c verbCreatingFunctions/sunoptikos_mellontas.c verbCreatingFunctions/parakeimenos.c verbCreatingFunctions/upersuntelikos.c 
	./generateVerbs

3:
	gcc -o checkHeart verbsChecker.c
	./checkHeart ζηλεύουμε

4:
	gcc -o verbId verbsIdentifier.c
	./verbId ζηλεύουμε

clean:
	rm  generateDatabases generateVerbs checkHeart verbId
	rm ../generatedDatabases/greekRimata.txt 
	rm ../generatedDatabases/greekRimataCreator.txt 
	rm ../generatedDatabases/greekYpoloipa.txt
	rm ../generatedDatabases/greekRimataCreator.txtSorted.txt