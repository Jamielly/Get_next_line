# GET_NEXT_LINE

## Description

The goal of this project is to write a function that returns a line read from a file descriptor
The main challenge lies in handling variable buffer sizes and using static variables to preserve data between successive calls.

## Project Overview

The implementation allows reading the contents of a file or standard input line by line until the end

- Supports multiple file descriptors (Bonus).
- Efficient memory management with malloc and free
- Flexible compilation with BUFFER_SIZE defined at compile time

## Function Prototype

`char *get_next_line(int fd);`

## Allowed External Functions

- `read`
- `malloc`
- `free`

## Project Structure

 ├── get_next_line.c       
 ├── get_next_line_utils.c 
 ├── get_next_line.h       
 └── README.md            

``
FD
 ↓
read_and_join   → enche stash até ter '\n'
 ↓
extract_line    → pega linha pronta
 ↓
clean_stash     → remove linha usada
 ↓
return line
``

## Instructions
### Requirements

- cc compiler (or gcc/clang)
- UNIX operating system (Linux or macOS).

### Compile

The function must be compiled with the flag -D BUFFER_SIZE=n:

`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`

## Algorithm Explanation

The algorithm uses a static variable to store data that has been read from the file but has not yet been returned as a line

 - Reading: The function reads the file in blocks of size BUFFER_SIZE until it encounters a newline character (\n) or the end of the file.

- Extraction: Once the \n is identified, the line is extracted from the accumulated buffer and prepared for return.

- Preservation: The remaining content read after the \n is kept in the static variable for the next call to the function. This method is justified by the need to avoid losing data between buffer reads, which may contain parts of multiple lines.

## Resources
### AI Usage
Artificial Intelligence tools were used as learning aids to:

- Clarify the concept of static variables

- Understand the behavior of the file system and file descriptors.

- Assist in debugging memory leaks and edge cases (buffers that are too small or too large).

*Note*: All implementations and final tests were performed manually to ensure mastery of the material.

## What I Learned

This project deepened my understanding of:

- Static variables in C and their lifetime.

- Dynamic memory management (heap).

- Handling file descriptors and the `read` system call.

- Buffer logic and low-level string processing.

---

## Author

Jamielly R.

GitHub: https://github.com/Jamielly
