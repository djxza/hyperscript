
Lexical Analysis (Scanning):

This stage involves breaking the input program into tokens (individual units such as keywords, identifiers, operators, etc.).
You would typically define rules using regular expressions to identify and tokenize different parts of the input code.
Syntax Analysis (Parsing):

In this stage, the tokens generated by the lexical analyzer are analyzed to determine if they form valid syntax according to the grammar of the programming language.
This stage often involves building a parse tree or an abstract syntax tree (AST) representing the structure of the program.
Semantic Analysis:

Here, the compiler checks whether the parsed program adheres to the semantic rules of the language.
It involves type checking, ensuring variables are declared before use, and other semantic validations.
Intermediate Code Generation:

The compiler may translate the input program into an intermediate representation (IR) that is easier to analyze and optimize.
This IR can be in the form of a high-level language or a lower-level representation like assembly language.
Optimization:

The compiler may perform various optimizations on the intermediate representation to improve the efficiency of the generated code.
Common optimizations include constant folding, dead code elimination, loop optimization, etc.
Code Generation:

Finally, the compiler translates the optimized intermediate representation into machine code or bytecode suitable for execution on the target platform.
This stage involves mapping high-level constructs to low-level instructions specific to the target architecture.