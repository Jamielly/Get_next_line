<p align="center">
  <img src="https://img.shields.io/badge/42-get__next__line-000000?style=flat-square&logo=42&logoColor=white" alt="42 project"/>
  <img src="https://img.shields.io/badge/language-C-blue?style=flat-square" alt="C language"/>
  <img src="https://img.shields.io/badge/norm-compliant-success?style=flat-square" alt="Norm compliant"/>
</p>

<p align="center"><i>This project has been created as part of the 42 curriculum by jamsilva</i></p>

<h1 align="center">GET_NEXT_LINE</h1>

> A C function that reads any file descriptor line by line — regardless of buffer size — using static variables to persist state between calls.

---

## 📑 Table of Contents
- [Description](#description)
- [Project Overview](#project-overview)
- [Function Prototype](#function-prototype)
- [Allowed External Functions](#allowed-external-functions)
- [Project Structure](#project-structure)
- [Instructions](#instructions)
- [Usage](#usage)
- [Algorithm Explanation](#algorithm-explanation)
- [Edge Cases](#edge-cases)
- [Resources](#resources)
- [What I Learned](#what-i-learned)

---

## Description
The goal of this project is to write a function that returns one line at a time from a *file descriptor*. The main challenge lies in handling variable buffer sizes and using **static variables** to preserve data between successive calls, enabling sequential reading of files or standard input (`stdin`).

---

## Project Overview

| Aspect | Approach |
|---|---|
| **Memory management** | Strict use of `malloc`/`free` with no memory leaks |
| **Flexible compilation** | `BUFFER_SIZE` defined at compile time for efficiency testing |
| **Bonus** | Multiple simultaneous file descriptors with a single static variable |
| **Norm** | Code complies with 42's Norminette |

---

## Function Prototype
```c
char *get_next_line(int fd);
```

---

## Allowed External Functions
- `read`
- `malloc`
- `free`

---

## Project Structure
```text
.
├── get_next_line.c       # Core logic and static variable management
├── get_next_line_utils.c # Helper functions (strjoin, strlen, strchr, etc.)
├── get_next_line.h       # Prototypes and macro definitions
└── README.md             # Project documentation
```

---

## Instructions

### Requirements
- `cc` compiler (or `gcc`/`clang`)
- UNIX operating system (Linux or macOS)

### Compile
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Check for memory leaks
```bash
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

---

## Usage
Include the header and call the function in a loop until it returns `NULL`.

```c
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // mandatory: each returned line is heap-allocated
    }
    close(fd);
    return (0);
}
```

---

## Algorithm Explanation

The core mechanism relies on a **static variable** — the *stash* — which acts as a buffer between `read` calls and the caller. Data read from the file accumulates there until a full line is ready to be returned.

```
FILE DESCRIPTOR (fd)
        │
        ▼
┌───────────────────┐
│  read_and_join    │  reads BUFFER_SIZE bytes, appends to stash
└────────┬──────────┘
         │  repeat until '\n' found or EOF
         ▼
┌───────────────────┐
│  extract_line     │  slices everything up to and including '\n'
└────────┬──────────┘
         │
         ├──────────────────────────────────┐
         ▼                                  ▼
┌───────────────────┐            ┌────────────────────┐
│  return line      │            │  clean_stash       │
│  (to caller)      │            │  (keep remainder)  │
└───────────────────┘            └────────────────────┘
```

**Step by step:**

1. **Read** — `read()` fills a temporary buffer of `BUFFER_SIZE` bytes. That content is joined onto the stash.
2. **Check** — the stash is scanned for `\n`. If none is found and EOF has not been reached, reading continues.
3. **Extract** — everything up to and including the first `\n` is allocated as the return string.
4. **Polish** — whatever remains in the stash after the `\n` is preserved for the next call.
5. **Memory** — all temporary buffers are freed before returning; only the extracted line is handed to the caller.

**Why a static variable?** The `read` system call does not know about line boundaries. A single `read` may return part of the current line, the `\n`, *and* the beginning of the next line. Without a persistent stash, that overflow data would be permanently lost when the function returns.

---

## Edge Cases

| Scenario | Behavior |
|---|---|
| No trailing `\n` | Last line is returned correctly, null-terminated with `\0` |
| EOF with empty stash | Returns `NULL` — signals end of input |
| `read` returns `-1` | Frees internal memory and returns `NULL` — no undefined state |
| `BUFFER_SIZE = 1` | Correct, but slow — one byte per `read` call |
| Very large `BUFFER_SIZE` | Correct — stash absorbs all overflow beyond the current line |
| Empty file | Returns `NULL` on the first call |
| Multiple fds (bonus) | Each fd is tracked independently via indexed stash |

---

## Resources

### Documentation
- `man 2 read` · `man 2 open` · `man 2 close`
- 42's Subject PDF and Norm document

### AI Usage
AI tools were used as learning assistants to:
- Clarify the scope and lifetime of **static variables**
- Debug memory leaks and understand pointer management with dynamic buffers
- Generate test cases for extreme `BUFFER_SIZE` values (e.g., `1` or `10000000`)

*All final logic and implementation were written manually to ensure the technical mastery required by 42.*

---

## What I Learned
- How **static variables** persist across function calls — and why that matters for stateful I/O
- Manual heap memory management and preventing segmentation faults
- Low-level interaction with the filesystem via `read` and file descriptors
- Buffer-boundary thinking: writing code that is correct regardless of how much `read` returns at once

---

<p align="center">
  <b>Author:</b> Jamielly R. &nbsp;|&nbsp;
  <b>42 Login:</b> jamsilva &nbsp;|&nbsp;
  <b>GitHub:</b> <a href="https://github.com/Jamielly">Jamielly</a>
</p>
