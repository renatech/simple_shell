# Simple Shell

## Overview
Welcome to the Simple Shell project! This repository contains the code for a simple UNIX command line interpreter. It is designed to follow the requirements set forth in each version of the project, starting from Simple Shell 0.1 and progressing through more advanced features and improvements.

## Project Structure
The project is organized into multiple versions, each building upon the previous one. Below is an overview of the project versions:

### Simple Shell 0.1
- Basic shell functionality.
- Displays a prompt and waits for user input.
- Executes simple, single-word commands.
- Handles command not found errors.
- Handles Ctrl+D (End of File) gracefully.

### Simple Shell 0.2
- Extends Simple Shell 0.1 by adding the ability to handle commands with arguments.

### Simple Shell 0.3
- Extends Simple Shell 0.2 by adding PATH handling and preventing unnecessary forks when a command does not exist.

### Simple Shell 0.4
- Implements the 'exit' built-in command to exit the shell gracefully.

### Simple Shell 1.0
- Implements the 'env' built-in command to display the current environment.
- Handles setenv and unsetenv built-in commands to modify environment variables.
- Implements the 'cd' built-in command to change the current directory.
- Handles commands separated by semicolons (';').
- Implements logical operators '&&' and '||'.
- Adds support for aliasing commands.
- Handles variables replacement, including $? and $$.
- Supports comments in the form of '#'.

### Simple Shell 0.1.1 (Advanced)
- Implements a custom getline function to read user input efficiently using a buffer.

### Simple Shell 0.2.1 (Advanced)
- Excludes the use of strtok to parse commands.

### Simple Shell 0.4.1 (Advanced)
- Allows for passing an exit status when using the 'exit' built-in.

### Setenv and Unsetenv (Advanced)
- Implements the setenv and unsetenv built-in commands.

### CD (Advanced)
- Extends 'cd' command functionality to handle additional cases and update the PWD environment variable.

### Commands Separator ';' (Advanced)
- Handles multiple commands separated by semicolons (';').

### Logical Operators '&&' and '||' (Advanced)
- Implements logical operators for shell commands.

### Alias (Advanced)
- Adds support for aliasing commands with customizable values.

### Variables (Advanced)
- Handles variable replacement, including special variables like $? and $$.

### Comments (Advanced)
- Supports comments in shell scripts.

### File as Input (Advanced)
- Allows the shell to read commands from a file provided as a command-line argument.

## Usage
To use this shell, clone the repository and compile the code. Then, you can run the shell by executing the resulting binary. Here's an example of how to run the Simple Shell:

```bash
$ make
$ ./simple_shell
```

## Contributors
This project is maintained and developed by [Your Name] and [Your Collaborator's Name]. Feel free to contribute, report issues, or suggest improvements to help make this shell even better!
