# customTypes
customTypes such as integers, strings, etc.

String Type:
This is an implementation of a custom type for representing strings in C++. The following operations as well as operators are implemented, using dynamic memory allocation.

Operations:
- length: determine the length of string
- upper: convert the string to upper case
- lower: convert the string to lower case
- at: return character at a given index
- substring: extract a substring from the given start and end indexes
- index: find starting index of a substring
- compare: compare two strings
- concat: concatenate/append the argument after current string
- prepend: concatenate/append the argument before current string

Operators:
- '+' : for concatenation and prepend operations (different data types and order of arguments are taken into account)
- '=' : for assignment
- '==', '!=', '<' and '>' : for comparison operations
- '[ ]' : for access to character at a given index
- '>>' and '<<' : for output and input a string
