# cc-lab

Name: Iqra Rafiq
Roll No: 2021cs134
Section: C


Overview
The CC Compiler Parser is a lightweight C-like language parser and compiler designed to translate source code written in a simplified C syntax into machine-readable instructions or an intermediate representation. This project implements the basic structure of a compiler, including lexical analysis, syntax parsing, and code generation.

Features
Lexical Analysis (Tokenization): Converts source code into tokens (keywords, operators, identifiers, etc.) using a tokenizer.
Syntax Analysis (Parsing): Builds an abstract syntax tree (AST) from the tokens, ensuring the code follows the correct grammar.
Semantic Analysis: Verifies variable declarations, data types, and the correct use of operations in the code.
Code Generation: Translates the AST into machine code, intermediate code, or another form of executable output.
Error Handling: Provides meaningful error messages during lexical and syntax analysis to help debug faulty code.

Key Components
Lexer: The lexical analyzer scans the input program and converts it into a series of tokens. These tokens are then passed to the parser.

Parser: The syntax analyzer (parser) checks for correct syntactical structure based on grammar rules, building an abstract syntax tree (AST).

Semantic Analyzer: Ensures variables and functions are declared before use, verifies data type compatibility, and ensures valid expressions.

Code Generator: Takes the AST and generates executable or intermediate code. This can be machine code, bytecode, or assembly language.
