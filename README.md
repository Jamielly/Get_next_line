<i>This project has been created as part of the 42 curriculum by **jamsilva**</i>

# GET_NEXT_LINE

![Language](https://img.shields.io/badge/language-C-blue.svg)
![42](https://img.shields.io/badge/42-Get_next_line-black.svg)
![Status](https://img.shields.io/badge/status-Completed-success.svg)
![Score](https://img.shields.io/badge/🏆-125%2F100-brightgreen)
![Norminette](https://img.shields.io/badge/norminette-passing-brightgreen.svg)

## Description

**get_next_line** is one of the core projects of the 42 curriculum. The objective is to implement a function capable of reading a file descriptor **one line at a time**, regardless of the size of the file or the value of `BUFFER_SIZE`.

The main challenge is preserving unread data between function calls using **static variables**, while ensuring efficient memory management and handling edge cases correctly.

---

# Features

* Read one line at a time from any file descriptor.
* Works with files, standard input, and pipes.
* Supports any compile-time `BUFFER_SIZE`.
* Preserves unread data between successive calls.
* Proper dynamic memory management.
* No memory leaks.
* Supports multiple file descriptors simultaneously (Bonus).

---

# Function Prototype

```c
char *get_next_line(int fd);
```

---

# Allowed Functions

* `read`
* `malloc`
* `free`

---

# Project Structure

```text
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
└── README.md
```

---

# How It Works

```text
                 get_next_line(fd)
                         │
                         ▼
               Read BUFFER_SIZE bytes
                         │
                         ▼
              Append data into stash
                         │
          ┌──────────────┴──────────────┐
          │                             │
     '\n' found?                     EOF?
          │                             │
          ▼                             ▼
 Extract current line          Return remaining data
          │
          ▼
 Clean stash
          │
          ▼
     Return line
```

---

# Mandatory vs Bonus

| Feature                               | Mandatory | Bonus |
| ------------------------------------- | --------- | ----- |
| Read line by line                     | ✅         | ✅     |
| Configurable `BUFFER_SIZE`            | ✅         | ✅     |
| Dynamic memory management             | ✅         | ✅     |
| Static buffer                         | ✅         | ✅     |
| Multiple file descriptors             | ❌         | ✅     |
| Independent reading state for each FD | ❌         | ✅     |

---

# Mandatory Implementation

The mandatory implementation uses a single static variable to preserve unread data between successive calls.

```text
          FILE
            │
            ▼
         read()
            │
            ▼
      static stash
            │
            ▼
 extract next line
            │
            ▼
 return line
```

Since only one static buffer exists, only one reading state is preserved.

---

# Bonus Implementation

The bonus version extends the mandatory implementation by allowing **multiple file descriptors** to be read simultaneously.

Instead of using one static buffer:

```c
static char *stash;
```

the bonus version keeps one buffer for each file descriptor:

```c
static char *stash[OPEN_MAX];
```

Each file descriptor preserves its own unread data independently.

```text
               Bonus

FD 3 ─────────► stash[3]

FD 4 ─────────► stash[4]

FD 5 ─────────► stash[5]

FD 6 ─────────► stash[6]
```

This allows interleaved reading without losing the current position of any file.

Example:

```c
get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);
get_next_line(fd3);
get_next_line(fd2);
```

Each file descriptor continues exactly where it previously stopped.

---

# Algorithm

Each function call performs four steps:

### 1. Read

Read data from the file descriptor until:

* a newline (`\n`) is found, or
* the end of the file (EOF) is reached.

---

### 2. Store

Append the newly read bytes into the persistent buffer (`stash`).

---

### 3. Extract

Extract the next complete line to be returned.

---

### 4. Preserve

Keep the remaining unread bytes inside the static buffer for the next call.

---

# Compilation

Compile using any desired `BUFFER_SIZE`.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

---

# Usage

Include the header and repeatedly call `get_next_line()` until it returns `NULL`.

## Example

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

---

# Bonus Test

Create three text files:

```
arquivo1.txt
arquivo2.txt
arquivo3.txt
```

Compile using the bonus files:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line_bonus.c \
get_next_line_utils_bonus.c \
main_bonus.c \
-o gnl_bonus
```

Example test:

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("arquivo1.txt", O_RDONLY);
	fd2 = open("arquivo2.txt", O_RDONLY);
	fd3 = open("arquivo3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);

	line = get_next_line(fd1);
	printf("FD1 -> %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("FD2 -> %s", line);
	free(line);

	line = get_next_line(fd1);
	printf("FD1 -> %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("FD3 -> %s", line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);
}
```

---

# Running

```bash
./gnl_test
```

Bonus:

```bash
./gnl_bonus
```

---

# Memory Leak Check

Using Valgrind:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./gnl_test
```

or

```bash
valgrind --leak-check=full --show-leak-kinds=all ./gnl_bonus
```

---

# Edge Cases Covered

* Empty files
* Files ending without `\n`
* Files containing only `\n`
* Very small `BUFFER_SIZE`
* Very large `BUFFER_SIZE`
* Invalid file descriptors
* Standard input
* Multiple simultaneous file descriptors (Bonus)

---

# AI Usage

Artificial Intelligence was used strictly as a learning tool to:

* clarify the behavior of static variables;
* better understand file descriptors and the `read()` system call;
* discuss edge cases;
* assist in debugging memory management.

All implementation decisions, coding, testing, debugging, and final validation were completed manually.

---

# What I Learned

This project significantly improved my understanding of:

* Static variables and persistent state.
* Dynamic memory allocation.
* Ownership of allocated memory.
* Low-level file I/O using `read()`.
* Buffer management.
* String manipulation without relying on the standard library.
* Defensive programming.
* Memory leak prevention.
* Handling multiple file descriptors independently (Bonus).

Implementing the bonus version reinforced how independent execution states can be maintained simultaneously using indexed static storage.

---

# Author

**Jamielly R.**

GitHub: https://github.com/Jamielly

42 Login: **jamsilva**
