# NOTES FOR FINAL EXAM

### TERMINAL COMMANDS
- `pwd` :: prints the current working directory to the terminal
- `ls` :: displays all files and directories within the current working directory
- `cd <path>` :: move between directories from where you currently are
    - chain `cd` by using `/` between directories
    - go back one directory by using `..`
    - entering just `cd` will send you to your root directory
        - on macOS, this is `/~`
- `mkdir <path>` :: creates a new directory given a path
    - entering just the name of the directory will make the new directory in the current directory
- `rm <path>` :: deletes a file given its path
    - entering just the name of the file when in its directory will delete the file from there
- `rm -rf <path>` :: deletes a directory and all the contents within in
    - `-r` represents recursion, or the deletion of all files and subdirectories within a directory
    - `-f` represents force, which means it won't prompt you for permission
- `cp <path1> <path2>` :: copies a file from path1 to path2
    - you can use `-r` to copy directories as well
    - something like `cp test.txt new.txt` will copy a file called test.txt in the cwd and write it to a new file new.txt in the same directory
- `mv <path1> <path2>` :: moves a file from path1 to path2
    - not only can you move files into different directories..
    - but you can also rename files!
        - `mv old.txt new.txt` will simply change the name of the file, keeping its contents

### GIT COMMANDS
- `git add <file1> ...` :: stage changes of file(s) for a commit
    - can chain as many files as you want
    - can only perform on file types that are not within .gitignore (files that are being tracked)
    - can do `git add *` to add all non-ignored (not tracked) files that have changes
- `git commit` :: records staged changes to the local repository's history
    - traditionally, just doing git commit will open up vim or another editor for you to type
    your commit message
    - `git commit -m <message>` will instead let you write your commit message in-line
    - `git commit -a` will automatically perform `git add *` for all tracked files and commit in the same command
    - `git commit -am` combines the functionality of the previous two commands
- `git push <remote> <branch>` :: uploads local commits to a remote repository
    - the `<remote>` field control the repository you upload to, which is by default "origin" when you clone a repository
    - the `<branch>` field controls which branch of the repository you upload to. by default, git repos have branch main
    - you can set the upstream that enables easy `git push` which will track both the remote and branch automatically
- `git pull <remote> <branch>` :: fetches and integrates changes from a remote repository to your local repository
    - the `<remote>` field controls the repository that you pull from. default is "origin" when you clone
    - the `<branch>` field controls which branch you pull from. by default, the remote repository will have "main"
    - you can set the upstream that enables easy `git pull` which will track both the remote and branch automatically
- `git checkout <branch>` :: switches between braches of your repository
    - you can use `git checkout -b <branch>` to create a new branch for your repository with name `<branch>`

### STDIN
- Two commands to gather input from the input stream:
- `std::cin >> <string>`
    - `std::cin` gathers text up until the first whitespace or newline it encounters
    - notably, if there is numerous whitespace between two portions of text, `std::cin` will skip over it
    - for example, two calls of `std::cin` on `hello   there` will yield "hello" and "there" in the resepective variables
    - `std::cin` leaves a `\n` in the input buffer from the user pressing enter, which can cause conflicts with `std::getline`
        - therefore, it is best too not use these two together
- `std::getline(<istream>, <string>)`
    - `std::getline` can take input either from `std::cin` directly or a files input stream
    - and output it in the specified `<string>` field (usually put it into a string variable)
    - it will read cin or a file up until it discovers a new line, meaning it will read in whitespace
    - useful for parseable inputs or like previously stated file reading

### ZERO VS NON ZERO RETURNS
- it is standard practice for main to end in `return 0`
- in fact, the compiler will include this for you if you forget!
- `return 0` by convention signals a successful output
- `return x`, where x is a non-zero value, is typically ascribed to an unsuccessful output
- it is simply convention and not enforced but should be followed for clarity
    - you would generally prefer to use std::cerr for more detailed error messages in complex programs

### INCLUDE
- `#include <file>` is a command used to incorporate the contents of one file into another
- includes go at the top of the file before anything else
- and there are some conventions to follow when writing them!
- if you are including standard library header files:
    - These are the first thing you put at the top of the file
    - if you wanted to include string, you would write:
        - `#include <string>`
    - note how string is encased in `<>` and *does not* include `.h`!
    - also note that you could also write this as `#include "string.h"` (Not Encouraged!)
- if you are including your own header files:
    - these should be placed after the standard library header files
    - if you created a header file titled `calc.h`, you would write:
        - `#include "calc.h"`
    - note how we replace `<>` with `""`, and include `.h`!
- **THE REASON YOU WANT TO USE <> OR "" RESPECTIVELY IS BECAUSE IT CHANGES WHERE THE COMPILER WILL SEARCH FOR FILES FIRST. IF YOU USE ANGLE BRACKETS, IT WILL LOOK IN SYSTEM PATHS FIRST, WHICH IS WHERE STANDARD LIBRARIES LIVE ON YOUR MACHINE. IF YOU USE QUOTES, IT WILL SEARCH THE LOCAL DIRECTORY FIRST, WHICH IS OFTEN WHERE HEADER FILES YOU CREATE WILL LIVE (LIKE IN A FOLDER TITLED INCLUDE).**

### PROGRAM COMPILATION
- We start all compilations with `c++`
- then if we have any includes, we can use `-I` followed by the folder that contains the includes
    - so if you are in a root directory with an include folder, you want:
        - `c++ -Iinclude/ <everything else>`
    - note the lack of anything between -I and the folder
    - the path starts IMMIDIATELY after the -I
- Then we can add all of the `.cpp` files that we need to run our program
- we can do one or numerous `.cpp` files
    - `c++ main.cpp`
    - `c++ main.cpp other.cpp ...`
- we can even do whole directories of `.cpp` files!
    - `c++ src/*.cpp`
- we can change the name of the `.out` file using the `-o` flag:
    - `c++ main.cpp -o myprogram.out`
- we can specify which version of c++ we want to use when we compile with the `-std=` flag:
    - `c++ main.cpp -std=c++17`
- Putting it all together, if we had a program with headers and src files that we wanted to compile in c++17:
    - `c++ -Iinclude src/*.cpp -o this_program.out -std=c++17`

### PRAGMA ONCE
- we want guards on our header files to prevent them from being included multiple times on accident
- for this, we can simply include `#pragma once` at the top of our header files
- this will make it so that a header files contents are only processed **1** time during compilation of a src file
- this will protect it against numerous inclusions, whether directly or indirectly through other header files
- you could also use `#ifndef`, `#define`, and `#endif`, which accomplishes the same thing as `#pragma once`
- The result of using `#pragma once` properly in your program is that you will avoid **redefinition errors** and your time to compile will increase

### NAMESPACES
- the purpose of making namespaces is prevent naming collisions and group code logically
- lets say we are making use of two libraries that both have a function print()
    - `void print(int)`
    - `void print(const std::string&)`
- without namespaces, if we imported these two libraries and tried to call print, the compiler would complain
- it wouldn't know which one to use!
- however, if we were to create namespaces for each:
    - `namespace LibA { void print(int); }`
    - `namespace LibB { void print(const std::string&); }`
- we could now safely call both libraries prints:
    - `LibA::print(5);`
    - `LibB::print("Hello");`
- with this we also get the convenience function `using`, where we can reduce the amount of code we type by telling the compiler we know what we are using
- take the snippet `using std::cout, std::endl;`:
    - now, instead of writing:
        - `std::cout << "Hello!" << std::endl;`
    - we can instead write:
        - `cout << "Hello!" << endl;`
- we save some space, but we should **never use `using` in header files**. It can cause conflicts because all `.cpp` files that inherit from the header will have this namespace convenience

### EXCERCISE: SHELL COMMANDS
- Create a directory named "proj"
    - `mkdir proj`
- Move into it
    - `cd proj`
- Create an empty file named "data.txt"
    - `touch data.txt` OR `vim data.txt` + `:wq`
- Copy it into "backup.txt"
    - `cp data.txt backup.txt`
- Delete "backup.txt"
    - `rm backup.txt`
- Remove entire "proj" directory
    - `cd ..` + `rm -rf proj` OR `rm -rf ../proj`

### EXCERCISE: GIT BASICS
- You made changes to main.cpp. Write the git commands to:
    1. Stage the file
    2. Commit it with message "fix bug"
    3. Push it
    4. Create ans switch to a new branch named featureX
- Answer:
    1. `git add main.cpp`
    2. `git commit -m "fix bug"`
    3. `git push`
    4. `git checkout -b featureX`
- alternative answer (assuming main is the only thing you changed):
    1. `git commit -am "fix bug"`
    2. `git push`
    3. `git checkout -b featureX`

### EXCERCISE: INCLUDES
- State which includes should be used for the following examples. Explain:
    1. vector
    2. myheader.h
- answers:
    1. The correct form is `#include <vector>`. This is because "vector" is part of the standard library. It is desirable to use angle brackets because they search system paths first, which is where "vector" would live closer to.
    2. The correct form is `#include "myheader.h"`. This is because "myheader.h" is not part of the standard library. It is desirable to use quotes because they search local directories first, where something like "myheader.h" would live (in a folder like include).

### EXCERCISE: COMPILE
- Write the c++ command to compile a program given that `main.cpp` is in "src/main.cpp", and `project.h` is in an include "directoryprog":
    - `c++ -Iinclude src/main.cpp -o program.out -std=c++17`

### EXCERCISE: PRAGMA ONCE
- Explain what `#pragma once` does and why it is helpful:
    - pragma once prevents header files from being included multiple times by a given program or `.cpp` file, regardless if it has multiple includes of the same file or other header files also include the file. The result of this is that their won't be any redefinition errors and compile time is sped up.

### STRING FUNCTIONS + INSIGHTS
- Assume defined string `std::string s = "Hello World!";`
- `size_t std::string::size()`
    - Use Case: `s.size()` -> `12`
    - Note that `s.length()` does the same thing and follows the same pattern.
    - returns the total length of the string, or the number of characters that it contains
    - invoked as a dot function that takes no arguments
- `std::string substr(size\_t pos = 0, size\_t len = npos) const;`
    - Use Cases:
        1. `s.substr()` -> `Hello World!`
        2. `s.substr(0,5)` -> `Hello`
        3. `s.substr(5,6)` -> `World!`
        4. `s.substr(0,99)` -> `Hello World!`
        5. `s.substr(1,0)` -> `''`
        6. `s.substr(99,3)` -> `Exception: std::out_of_range`
    - substr takes in a starting position, pos, and a number of characters, len, and returns a substring based on those two values
    - By default, pos = 0 and len = npos, meaning the default output of substr with no args will return the original string
    - assuming a pos that is non-zero, giving len a value greater than 0 will output a string of size len, that contains characters starting from index=pos to index=pos+len (including the final indexed value). 
    - if substr is given a length that would have it go outside the bounds of the string, it will simply return the string from the given starting position to end.
    - if a pos is given that exceeds a valid position in the string, it will throw and exception. if len is 0 substr will return `''`
- `std::string::npos`
    - this is used for a variety of cases. It holds the value -1, which because the value itself is of type `size_t`, will return the maximum possible value of `size_t`. It guarantees that it evalutates to an "out-of-bounds" index
    - Notably, strings built in functions make use of this to indicate index errors or to get "until end of string" values.
    - substr uses it as the default length
    - `std::string::find` will return this value if it fails to find its given string within another string
- `size_t find(std::string str, size_t pos=0)`
    - this is used to return the index of a substring found with another string
    - used by doing:
        - `s.find(my_substr, [optional pos]);`
    - it will find a substr with a string s with the dot operator
    - if it finds the substr, it will return the starting index from which the substring is found
    - you can optionally give it a `size_t pos`, which defaults as 0, to only check a string from a certain index onwards
    - if it fails to find the substr, it will return `std::string::npos`

### EXCERCISE: SIZE\_T AND NPOS
- Explain:
    1. What type `size_t` represents
    2. what `std::string::npos` means
- Answers:
    1. `size_t` is a type that represents all possible positive integer values. it allows a greater range of positive numbers to be accessed by having the sign bit used to represent magnitude. This doubles the amount of positive values a standard int could hold. In other words, it is an unsigned int OR unsigned long. **an unsigned integer type used for sizes and indexes**
    2. `std::string::npos` represents `size_t` value -1, which is the highest possible unsigned long value available to your system. many string functions use it to signify error or inability to find a valid index. **signifies "not found"**

### EXCERCISE: C STRING VS STD::STRING
- List two major differences beteween C strings (`char*`) and C++ `std::string`
    1. `char*` is a a pointer to a list of characters that needs to be allocated space at compile time
    2. `std::string` is a list of characters that will dynamically allocate space as needed.
    3. C strings require manual size tracking; std::string knows its own length
    4. C strings are raw arrays of chars ending '\0' ; std::string manages memory automatically

### GLOBAL/STATIC VS STACK VS HEAP
- Global/Static Storage
    - global variables, static variables, string literals live here
        1. `int g = 5;`              // global
        2. `static int x = 10;`     // static local
        3. `const char* s = "hi";`   // string literal in static storage
    - exists for a programs entire lifetime (exists before main and after main)
    - created once, size is fixed at compile time
- The Stack
    - Function params, local variables, temporary objects, return addresses
        `void foo() {
            int x = 3;      // on the stack
            std::string s;  // the string object is on the stack; internal buffer may be heap
        }`
    - Lifetime of objects made on stack created when their scope begins
    - destroyed automatically at end of scope
    - very fast allocation, fixed size
- The Heap
    - Manually allocated objects or objects w/ smart pointers
        `int* p = new int(5);`
        `auto* arr = new double[1000];`
        `auto sp = std::make_unique<MyClass>();`
    - lifetime controlled manually with delete / delete[]
    - (or freed automatically w/ smart pointers)
    - slow allocation
    - flexible size, can be large (depends on system ram)

### EXCERCISE: MEMORY REGIONS
- classify each of the following vars as being stored on stack, heap, global/static memory:
`# include <iostream>
int g = 5;                  // (1)
int main () {
    int x = 10;             // (2)
    int* p = new int(20) ;  // (3)
    static int y = 7;       // (4)
    return 0;
}`
- answers:
    1. global/static
    2. stack
    3. heap
    4. global/static

### FREEING MEMORY
- When you allocate something on the heap, you must free it (unless its a smart pointer)
- For single objects, like an int, you can use `delete <var>`
- For non-singular objects, like lists or strings, you can use `delete[] <var>`

### CONST AND REFERENCES (&)
- you can put `const` before a type declaration to indicate that a variable should never have its value changed
    - trying to do so will cause an error
- you can call something by reference by putting `&` after its type to access the variable directly in a different scope
    - this prevents the compiler from creating a local copy
    - if you modify something called by reference it will change the original variable
- you can combine both to prevent the compiler from making a copy of a variable and preventing yourself from changing it on accident
    - this is best done for strings where it can be very expensive to make copies of

### UNSIGNED VS SIGNED
- signed values require a sign bit on a systems level which reduces the maximum range of values +/- in exchange for having both
- unsigned values free up the sign bit for magnitude, allowing more numbers in the positive direction
- if you were to do `unsigned int a = -5`, the value would wrap around and produce a very large positive number

### SPIRAL RULE
- start at variable, going up and to the right and reading it out
- when dealing with const, you should wrap it with the first thing to the left. if nothing is there, do it with the right instead. best visualized with `()`
- example:
    - `int *(*fp)(double);`
    - fp is a pointer
    - to a function that takes a double
    - and returns a pointer to int
- example:
    - `int* p;`
    - p is a pointer
    - to an int
    - *neither the pointer or data is const*
- example:
    - `const int* p`
    - `(const int)* p`
    - p is a pointer
    - to a const int
    - *the data is constant*
- example:
    - `int* const p = &x`
    - `int(* const) p = &x`
    - p is a const pointer
    - to an int
    - *the pointer is const*
- example:
    - `const int* const p = &x`
    - `(const int)(* const) p = &x`
    - p is a const *
    - to a const int
    - *both the data and pointer is const*

### GOTO
- dont use goto. it makes control flow hard and you should always use built in structures like for instead

### EXCEPTIONS
- try-throw-catch
    - Try: wrap around code that could result in an error
    - Throw: if an error occurs, thrown an exception
    - Catch: goes outside of the try block and gets evaluated if a corresponding throw is met

### STRUCT VS CLASS
- The only difference between struct and class is that struct is public by default and class is private by default

### PUBLIC VS PRIVATE VS PROTECTED
- public is accessible everywhere
- private is only accessible inside the class
- protected is only accesible in derived classes

### CLASS METHODS
- Methods are either defined inside the class body as normal
- OR you can define them outside the class doing ClassName::method

### ABSTRACT CLASSES, PURE METHODS, VIRTUAL METHODS
- a class is abstract if it has at least one pure virtual function
- you implement a pure virtual function by marking it `virutal` and ending it with `= 0;`
    - also known as a pure method
- you cannot instantiate an abstract class
- they are designed to force subclasses to declare certain functionalities
    - note that these implemented functions should use the `override` keyword at the end of their declaration

### EXCERCISE: VIRTUAL METHODS
- given a base pointer:
- `Shape* a = new Circle(2.0);`
- Explain why calling `s-\>area()` invokes the Circle version
    - `s->area` invokes the circle version because area() is virtual. C++ uses runtime dispatch (the vtable) to call the methods belonging to the actual object type, which is Circle and not shape.

### INHERITANCE AND SUBSUMPTION
- public inheritance: "is-a" relationship, public stays public
- protected inheritance: public becomes protected
- private inheritance: public becomes private
- subsumption: a derived object can be treated as a base object
    - works automatically with pointer and references
    - enables runtime polymorphism

### EXCERCISE: INHERITANCE MODES
- Given:
`class Base {
    public :
    void f () {}
};`
- Which of these allow calling d.f() from main?
    1. class D1 : public Base {};
    2. class D2 : protected Base {};
    3. class D3 : private Base {};
- Answer for each: allowed or not allowed?
    1. allowed
    2. not allowed
    3. not allowed

### FINAL, EXPLICIT, NOEXCEPT, OVERRIDE KEYWORDS
- final:
    - applied to a class to prevent further inheritance
    - applied to a virtual function prevents overriding
    - ex: `class Shape final { <class contents> };`
    - ex: `void f() override final {}`
- explicit:
    - function specifier used to prevent implicit type conversions in constructors and conversion operators
    - in other words, to use a function that requires a class made object, you would need to initialize or type cast a value to match it; the constructor loses the ability to automatically type cast for you
    - promotes cleaner, safer, and faster code
    - typically used on constructors that take a single argument
    - ex: `explicit Foo(double val) : value(static_cast<int>(val)) {}`
- noexcept:
    - tells the compiler that this function cannot throw an exception
    - if it does the program will terminate
    - but if true, allows the compiler to generate faster code that is less safe
    - ex: `void myFunction() noexcept`
- override:
    - a specifier that explicitly indicates a member function in a derived class is intended to override a virtual function in a base class
    - main advantage is that it signals other programmers that this function is mean to override, and will have the compiler throw an error if it is not actually overriding anything
    - otherwise, the compiler is smart enough to know when something needs to be overridden.
    - ex: `void f() override {}`

