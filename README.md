# Abstract-VM

Abstract-VM is the first C++ 42 school project. The objective is to practice in C++ and Object-Oriented Programming by coding a simple instruction executer & a lexer/parser.

In order to compile and use this program, you need a UNIX operating system, the clang++ compiler, the Bison and Flex softwares, and the Make software. All you need to do is to use the command `make` in the root folder of the project.

---

### What is Abstract-VM ?

Here is a small description of the program, as describe in the project subject:
```
AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.
```
More informations about the assembly language used in the project can be found in the project subject.


### Features

- Complete Lexer / Parser impementation using **yac**c and **flex** as a parser generator, in order to parse a pseudo assembly language.
- Use of **C++1z standard** for a better use of **C++ meta-programming**. (constexpr operations, templates, ...)
- Pseudo assembly language parsing and execution using a list to store instructions, and a stack to store and compute the data.


### How to use this program ?

In a command line interface, use the command `./abstract_vm` to print the usage. In order to execute a set of instructions, you either need to give the program a file with the instructions, or write them in the standard input (by giving `stdin` or `-` to the program).
