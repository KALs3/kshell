# KShell

A lightweight Unix shell written in C++ from scratch. KShell features a custom tokenizer with quote and escape handling, built-in commands, and external program execution via `fork`/`exec`.

![Shell Demo](https://img.shields.io/badge/version-1.0.0-blue)
![C++](https://img.shields.io/badge/C++-17+-orange)
![Platform](https://img.shields.io/badge/platform-Unix%20%7C%20Linux%20%7C%20macOS-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)

## Features

### Core Shell Features

* **Interactive prompt** with current working directory display
* **Command execution** for any program in `$PATH`
* **Argument handling** with proper space separation
* **Error handling** with descriptive messages

### Advanced Tokenizer

* **Quote support** — `echo "hello world"` is treated as a single argument
* **Escape sequences** — `echo hello\ world` joins arguments correctly
* **Mixed quotes and escapes** — `echo "quoted \"text\""` works as expected
* **Multiple spaces** — collapsed intelligently during parsing

### Built-in Commands

| Command | Description             | Usage                             |
| ------- | ----------------------- | --------------------------------- |
| `cd`    | Change directory        | `cd [path]` (defaults to `$HOME`) |
| `pwd`   | Print working directory | `pwd`                             |
| `exit`  | Exit the shell          | `exit`                            |

## Architecture

```text
┌─────────────────────────────────────────────────────────┐
│                    KShell Loop                          │
├─────────────────────────────────────────────────────────┤
│ Prompt → Read → Tokenize → Built-in? → Fork/Exec → Wait │
└─────────────────────────────────────────────────────────┘
```

## Learning Objectives

This project was built to better understand:

* **Process management** — `fork()`, `exec()`, `wait()`
* **String parsing** — state machines and tokenization
* **System calls** — `chdir()`, `getcwd()`, `execvp()`
* **Shell internals** — built-in commands vs external programs
* **C++ design** — modular architecture and header organization
* **Unix philosophy** — parent-child process relationships

## Building KShell

### Prerequisites

* C++17 compatible compiler (`g++` or `clang++`)
* Unix-like operating system (`Linux`, `macOS`, or `WSL`)
* `make`

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/KALs3/kshell.git
cd kshell

# Build the shell
make

# Run KShell
./kshell
```

## Limitations & Future Work

### Current Limitations

* No pipe support (`|`)
* No redirection (`>`, `<`, `>>`)
* No background jobs (`&`)
* No command history
* No tab completion
* No variable expansion (`$HOME`, `$PATH`)
* Physical paths only (no symlink awareness)

### Planned Improvements

* Add pipe and redirection support
* Implement background job control
* Add command history and tab completion
* Support environment variable expansion
* Improve path resolution and symlink awareness
