# THE ALX SIMPLE SHELL PROJECT

This is a simple UNIX command interpreter that works like the UNIX shell.
It is written in C.The shell supports executing commands, managing environment variables, and handling signals. Below is an overview of the main files in the project:


## Usage 

To run this shell

 1. clone the repository [here](https://github.com/coApollo/simple_shell.git
"clone simple shell")
 1. cd into the cloned repository in you computer
 1. compile the using this command
 ```bash

  gcc *.c -o hsh

 ```
 1. run the code "./hsh".
 ```bash

  ./hsh

 ```
 
A prompt will display and you can run the command that you want.


## Files

### main.h

This file contains all the prototypes and macros used
in the entire project

### main.c

This file contains the main function.

### execute.c

It the one responsible for the execution of commands using
execve system call

### environ.c

This file handles environment variables

### path.c

This file handles the path

 
