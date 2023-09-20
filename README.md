<h1 align="center">

0x16. C - Simple Shell

</h1>


<p align="center">

📄 🚀

</p>



## Description

<p>

This is a Milestone Project for the C code at ALX Africa Software Engineering, which involves the implementation of a shell program. The Gates of Shell project, developed during the first trimester, aims to help students gain an understanding of advanced concepts related to shell programming, such as process management, system calls, bit manipulation, file management, and error handling. The shell program is a straightforward UNIX command interpreter that mimics the features of the simple shell (sh). The project was coded exclusively in the C language.

</p>


## COPYRIGHT

Copyright (C) 2023 by [**Seyi Adegbite**](https://github.com/Sheyman0382) and [**Samuel Shielu**](https://github.com/saminstein) </br>

All rights reserved




## Installation

You can install the simple shell by cloning this repo:

```sh

$ git clone https://github.com/zinniewalter/simple_shell.git

```

Next you can compile the files with this command:

```sh

$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

```

finally you can run our Shell writing:

```sh

./hsh

```


## Features


    - Display a prompt and wait for the user to type a command. A command line always ends with a new line.

    - The prompt is displayed again each time a command has been executed.

    - The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

    - The command lines are made only of one word. No arguments will be passed to programs.

    - If an executable cannot be found, print an error message and display the prompt again.

    - If an executable cannot be found, print an error message and display the prompt again.

    - Handle errors.

    - You have to handle the “end of file” condition (`Ctrl+D`)

### Other features include:


    - Handle command lines with arguments

   ----

    - Handle the PATH

    - `fork` must not be called if the command doesn’t exist

   ----

    - Implement the exit built-in, that exits the shell

    - Usage: exit

    - You don’t have to handle any argument to the built-in exit

  ----

    - Implement the env built-in, that prints the current environment

  ----

 


