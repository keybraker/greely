# Lexical and Grammatical Analyzer for Greek with the use of Flex Bison

A new way to interpret and understand natural human language.
Greek as first language to be worked on.
Ai that understand and learns the human language and you.

## Getting Started

Just clone the project to your computer and run make, it's simple as that !

```
git clone git@github.com:keybraker/Lexical-Grammatical-Analyzer-for-Greek-with-Flex-Bison.git

```

### Prerequisites

Most Linux distros and Mac OS come preinstalled with all of the following compailers
but if you find any trouble, these are the links to follow:

* gcc - https://gcc.gnu.org
* flex - https://www.gnu.org/software/flex/
* bison - https://www.gnu.org/software/bison/

➽ In the end only gcc will be needed

### Installing

```
git clone git@github.com:keybraker/Lexical-Grammatical-Analyzer-for-Greek-with-Flex-Bison.git
```
enter the project folder via terminal

```
run command "make"
```
to clean all products created by the program run command "make clean"

## Running the tests

In order to run a test of your own you have to change input.
To do so, you need to go to input/input.txt and change the text.

```
"Καλημέρα, με λένε Ιωάννη και μαρέσει το ποδόσφαιρο." ➥ "To something else"
```

### Break down into end to end tests

The default input is "Καλημέρα, με λένε Ιωάννη και μαρέσει το ποδόσφαιρο."

If the default text is run, you will get the following outcome:

For example for the word "Καλημέρα" we get
```
Η λέξη από τον lex είναι: Καλημέρα
➥ λέξη είναι: Καλημέρα
  ➥ Το μέρος του λόγου είναι: Καλημέρα
   ➥ λέξεις μέρος του λόγου: Καλημέρα
```
For example for the word "Ιωάννη" we get
notice how it can undertand that "Ιωάννη" is a name
```
Το Ιωάννη είναι όνομα.
Η λέξη από τον lex είναι: Ιωάννη
➥ λέξη είναι: Ιωάννη
  ➥ Το μέρος του λόγου είναι: Ιωάννη
   ➥ λέξεις μέρος του λόγου: Καλημέρα , με λένε Ιωάννη
```
In the end if your text is correct the sentence will be completed shown bellow as continues line
```
    ➥ Η ολοκληρωμένη πρόταση είναι: Καλημέρα , με λένε Ιωάννη και μαρέσει το ποδόσφαιρο .
```

## Built With

* [c](https://gcc.gnu.org/) - The merging of all the parts and for batabase generation
* [flex](https://www.gnu.org/software/flex/) - The Lexical Analysis
* [bison](https://www.gnu.org/software/bison/) - The Grammatical Analysis

## Contributing

Please read [CONTRIBUTING.md](https://github.com/keybraker/Lexical-Grammatical-Analyzer-for-Greek-with-Flex-Bison/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

I use [SemVer](http://semver.org/) for versioning. For the versions available. 

## Authors

* **Ioannis Tsiakkas** - *(Keybraker)* - [Keybraker](https://github.com/keybraker)

## License

This project is licensed under the UOC License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Anthony Savidis
* HY340
