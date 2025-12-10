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
    - abc
