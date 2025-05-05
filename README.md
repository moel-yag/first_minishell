# Minishell Project

## Overview
Minishell is a simple shell implementation designed for the 42 school project. It aims to provide a basic command line interface that can execute commands, handle built-in functions, and manage user input through a linked list structure for command handling and error checking.

## Project Structure
The project is organized into several directories and files, each serving a specific purpose:

- **src/**: Contains the source code for the Minishell application.
  - **main.c**: Entry point of the application.
  - **shell/**: Implements the main shell functionalities.
    - **shell.c**: Contains the core shell logic.
    - **shell.h**: Header file for shell functions and structures.
  - **commands/**: Handles command execution and built-in commands.
    - **commands.c**: Implements command handling logic.
    - **commands.h**: Header file for command functions and structures.
  - **utils/**: Provides utility functions, including linked list management and error handling.
    - **linked_list.c**: Implements linked list functionalities.
    - **linked_list.h**: Header file for linked list operations.
    - **error_handling.c**: Contains error checking and handling functions.
    - **error_handling.h**: Header file for error handling functions.
  - **parser/**: Responsible for parsing user input into commands and arguments.
    - **parser.c**: Implements command parsing logic.
    - **parser.h**: Header file for parsing functions and structures.

- **includes/**: Contains common definitions and function prototypes used throughout the project.
  - **minishell.h**: Main header file for the project.

- **lib/**: Contains the Makefile for building the project.

- **Makefile**: Build instructions for the entire project.

## Setup Instructions
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Run `make` to compile the project.
4. Execute the compiled binary to start the Minishell.

## Usage
Once the Minishell is running, you can enter commands just like you would in a standard shell. The shell supports built-in commands and can execute external programs. Use `exit` to terminate the shell.

## Features
- Command execution with support for built-in commands.
- Error checking for command validity and formatting.
- Linked list implementation for managing commands and arguments.
- Command parsing to break down user input into executable components.

## Contributing
Contributions to the Minishell project are welcome. Please fork the repository and submit a pull request with your changes.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.