**Disclaimer[2]:**
> Continuation of the project has begun (Q3 instead of originally planned Q2), focus given on speed and optimization with core functionallity being added day by day. Main project is set to be finished until December-2018, if everything goes according to plan. Roadmap is to make a reliable exif tool for the Greek language, which will be enhanced.

**Disclaimer[1]:**
> This is a very early stage in the development of greely, key functions don't work, just the shell of the program is running, production will continue in Q2-18. Some adjustments have been to execute alot faster and run on UNIX based operating systems. Minor functionallity will be added in upcomming months but steady updates will continue in half a year.

***

![alt text](https://raw.githubusercontent.com/keybraker/Lexical-Grammatical-Analyzer-for-Greek/master/extras/IMAGES/greely_logo.png)

# Lexical and Grammatical Analyzer for Greek with the use of Flex Bison

A new way to interpret and understand natural human language.
Greek as first language to be worked on.
Ai that understands and learns the human language and you.

### Example

This example is a sentence in natural greek language:<br>
"Καλημέρα, με λένε Ιωάννη και μου αρέσει το ποδόσφαιρο."<br>
if given as input to Greely you will get the following output: 

```
Καλημέρα (ουσιαστικό, ενικού αριθμου , γένος θηλύκο , ονομαστική πτώση)  , κόμμα (σημείο στίξης)  
με (επεξηγηματικός σύνδεσμος)   λένε-[λέ]  'Ιωάννη' (όνομα αρσενικό)  και (συμπλεκτικός σύνδεσμος) 
μου (ουσιαστικό, ενικού αριθμου , γένος θηλύκο , ονομαστική πτώση)   αρέσει-[α]  
το (οριστικό άρθρο γένους ουδέτερο ενικού) 
ποδόσφαιρο (ουσιαστικό, ενικού αριθμου , γένος ουδέτερο , ονομαστική πτώση)  . τελεία (σημείο στίξης)
```

## Structure for interprentation 

```text
│ 
├── bison_flex
|   ├── analyzer
|   |   ├── greek_endings.h			// greek word endings
|   |   ├── greek_word_data.h			// greek word database
|   |   ├── word_exif_data_to_mem.c		// funcs for print	
|   |   ├── word_exif_data_to_mem.h		// funcs for print	
|   |   ├── word_syllab_arrays.h		// arrays for print
|   |   └── word_type_print.h			// helping funcs for print
|   |
|   ├── bison
|   |   ├── greek_protheseis.h 			// greek word protheseis
|   |   ├── greek_stikseis.h 			// greek word stikseis
|   |   ├── greek_sundesmoi.h 			// greek word sundesmoi
|   |   └── parser.y				// grammatical analyzer
|   |
|   └── flex
|       ├── greek_names.h 			// greek word names
|       └── scanner.l				// lexical analyzer
|
├── EXTRAS
|   ├── ANALYZER_OLD
|   |   ├── greek_endings_genos.txt		// greek endings genos
|   |   ├── name_gr.txt				// greek names
|   |   ├── greek_word_data.txt			// greek word database
|   |   ├── word_exif_data_to_mem.c		// funcs for print	
|   |   ├── word_exif_data_to_mem.h	
|   |   ├── word_syllab_arrays.h		// arrays for print
|   |   └── word_type_print.h			// helping funcs for print
|	|
|   ├── DATABASES
|   |   ├── l0_name.txt 			// greek database
|   |   ├── l1_database.txt 			// greek database
|   |   ├── t1_relations.txt			// greek database
|   |   ├── word_exif_database.xlsx		// greek database
|   |   └── word_exif_names.xlsx		// greek database
|   |
|   ├── IMAGES
|   |   └── greely_logo.png			// greely logo info
|   |
|   ├── MARKDOWNS
|   |   ├── CONTRIBUTING.md 			// Contribution Markdown
|   |   └── LICENSE.md				// License Markdown
|   |
|   └── WORD_EXIF_TOOL_CPP
|       ├── main.cpp 					
|       ├── Makefile					
|       ├── word_endings.hpp 			
|       ├── word_exif_data_to_mem.cpp	
|       └── word_exif_data_to_mem.hpp	
|
├── input
|   └── input.txt				// current input
│ 
├── output
|   └── blank					// compiled files
|
├── Makefile					// Makefile
└── README.md					// README MD
```

## Getting Started

### Prerequisites

Most Linux distros and Mac OS come preinstalled with all of the following compilers
but if you find any trouble, these are the links to follow:

* gcc - https://gcc.gnu.org
* flex - https://www.gnu.org/software/flex/
* bison - https://www.gnu.org/software/bison/

### Downloading

Clone the project to your computer and run make, it's simple as that !
```
git clone https://github.com/keybraker/Greely.git
```

### Running

enter the project folder via terminal and run command
```
make
```
to clean all products created by the program run command 
```
make clean
```

### Built With
* [c](https://gcc.gnu.org/) - The merging of all the parts and for database generation
* [flex](https://www.gnu.org/software/flex/) - The Lexical Analysis
* [bison](https://www.gnu.org/software/bison/) - The Grammatical Analysis

### Authors
* **Ioannis Tsiakkas** - *[Keybraker](https://github.com/keybraker)*

### Acknowledgments
* [CypressA](https://github.com/CypressA/GreekLex-2)

### Contributing
* [Contribution Refulations](https://github.com/keybraker/greek-Ai-Bot/blob/master/extras/MARKDOWNS/CONTRIBUTING.md)

### License
* [License Regulations](https://github.com/keybraker/greek-Ai-Bot/blob/master/extras/MARKDOWNS/LICENSE.md)

### Versioning
* [Versioning Regulations](http://semver.org/)
