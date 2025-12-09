# NOTES FOR FINAL EXAM

### TERMINAL COMMANDS
- `pwd` :: prints the current working directory to the terminal
- `ls` :: displays all files and directories within the current working directory
- `cd \<path\>` :: move between directories from where you currently are
    - chain cd by using "/" between directories
    - go back one directory by using ".."
    - entering just "cd" will send you to your root directory
        - on macOS, this is /~
- `mkdir <path>` :: creates a new directory given a path
    - entering just the name of the directory will make the new directory
    in the current directory
- `rm \<path\>` :: deletes a file given its path
    - entering just the name of the file when in its directory will
    delete the file from there
- `rm -rf \<path\>` :: deletes a directory and all the contents within in
    - "-r" represents recursion, or the deletion of all files and subdirectories within a directory
    - "-f" represents force, which means it won't prompt you for permission
- `cp \<path1\> \<path2\>` :: copies a file from path1 to path2
    - you can use "-r" to copy directories as well
    - something like `cp test.txt new.txt` 
