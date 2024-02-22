# Simple Shell Project

This project aims to create a simple UNIX command-line interpreter in C. The shell will provide basic functionality such as executing commands entered by the user, handling errors, and implementing built-in commands.

## Task Overview

### Task 0: Writing Beautiful Code
Before starting the implementation, ensure that the code follows the Betty coding style guidelines.

### Task 1: Simple Shell 0.1
- Display a prompt and wait for user input.
- Execute commands entered by the user.
- Handle errors such as command not found.

### Task 2: Simple Shell 0.2
- Enhance input parsing to handle commands with arguments.

### Task 3: Simple Shell 0.3
- Handle the PATH environment variable.
- Do not call fork() if the command doesn't exist.

### Task 4: Simple Shell 0.4
- Implement the exit built-in command to terminate the shell.

### Task 5: Simple Shell 1.0
- Implement the env built-in command to print the current environment variables.

### Task 6: Simple Shell 0.1.1
- Write a custom getline function to read user input efficiently.
- Use a buffer to minimize system calls.

### Task 7: Simple Shell 0.2.1
- Implement tokenization without using strtok().

### Task 8: Simple Shell 0.4.1
- Modify the exit command to accept an optional status argument.

### Task 9: setenv, unsetenv
- Implement the setenv and unsetenv built-in commands to modify environment variables.

### Task 10: cd
- Implement the cd built-in command to change the current directory.

### Task 11: ;
- Handle the command separator ";" to execute multiple commands sequentially.

### Task 12: && and ||
- Handle the shell logical operators "&&" and "||" to execute commands conditionally.

### Task 13: alias
- Implement the alias built-in command to define, list, and use aliases.

### Task 14: Variable
- Handle variables replacement such as "$?" and "$$".

### Task 15: Comments
- Handle comments indicated by "#" to ensure they do not affect command execution.

### Task 16: File as Input
- Allow the shell to take a file as a command-line argument and execute commands from it.

## Usage
To compile the shell program, run the following command:
```$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Contributing
Contributions are welcome! If you have any suggestions, improvements, or new features to add, feel free to submit a pull request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

