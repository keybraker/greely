#### Disclaimer: This is a very early stage in the development of greely, key functions don't work, just the shell of the program is running, production will continue in Q2-18. Some adjustments have been to execute alot faster and run on UNIX based operating systems. Minor functionallity will be added in upcomming months but steady updates will continue in half a year.

![alt text](https://raw.githubusercontent.com/keybraker/Lexical-Grammatical-Analyzer-for-Greek/master/greely%20logo.png)

# Lexical and Grammatical Analyzer for Greek with the use of Flex Bison

A new way to interpret and understand natural human language.
Greek as first language to be worked on.
Ai that understands and learns the human language and you.

## Structure for interprentation 

```text
│ 
├── bison_flex
|   ├── analyzer_funcs
|   |   ├── word_exif_data_to_mem.c // funcs for print
|   |   ├── word_exif_data_to_mem.h		
|   |   ├── word_syllab_arrays.h    // arrays for print
|   |   ├── word_type_print.h       // helping funcs for print
|   |   └── * databases             // current database
|   ├── bison
|   |   └── parser.y    // grammatical analyzer
|   └── flex
|       └── scanner.l   // lexical analyzer
|
├── database_generator
|   ├── realDatabase.c  // learning in proggress
|   └── * databases     // source database
|
├── input
|   └── input.txt       // current input
│ 
├── output
|   └── blank           // compiled files
|
├── Makefile
├── LICENSE
├── CONTRIBUTING.md
└── README.md
```

## Getting Started

### Prerequisites

Most Linux distros and Mac OS come preinstalled with all of the following compilers
but if you find any trouble, these are the links to follow:

* gcc - https://gcc.gnu.org
* flex - https://www.gnu.org/software/flex/
* bison - https://www.gnu.org/software/bison/

➽ In the end only gcc will be needed

### Downloading

Clone the project to your computer and run make, it's simple as that !
```
git clone https://github.com/keybraker/greek-Ai-Bot.git
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

### Example

This example is a sentence in natural greek language:
"Καλημέρα, με λένε Ιωάννη και μου αρέσει το ποδόσφαιρο.", 
if given as input to greekLex you will get the following output: 

```
Καλημέρα (ουσιαστικό, ενικού αριθμου , γένος θηλύκο , ονομαστική πτώση)  , κόμμα (σημείο στίξης)  
με (επεξηγηματικός σύνδεσμος)   λένε-[λέ]  'Ιωάννη' (όνομα αρσενικό)  και (συμπλεκτικός σύνδεσμος) 
μου (ουσιαστικό, ενικού αριθμου , γένος θηλύκο , ονομαστική πτώση)   αρέσει-[α]  
το (οριστικό άρθρο γένους ουδέτερο ενικού) 
ποδόσφαιρο (ουσιαστικό, ενικού αριθμου , γένος ουδέτερο , ονομαστική πτώση)  . τελεία (σημείο στίξης)
```

## Built With

* [c](https://gcc.gnu.org/) - The merging of all the parts and for database generation
* [flex](https://www.gnu.org/software/flex/) - The Lexical Analysis
* [bison](https://www.gnu.org/software/bison/) - The Grammatical Analysis

## Authors

* **Ioannis Tsiakkas** - *(Keybraker)* - [Keybraker](https://github.com/keybraker)

## Acknowledgments

* [CypressA](https://github.com/CypressA/GreekLex-2)

## [Contributing](https://github.com/keybraker/greek-Ai-Bot/blob/master/CONTRIBUTING.md)

## [License](https://github.com/keybraker/greek-Ai-Bot/blob/master/LICENSE)

## [Versioning](http://semver.org/)
