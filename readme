# KShell

A lightweight Unix shell written in C++ from scratch. KShell features a custom tokenizer with quote and escape handling, built-in commands, and external program execution via fork/exec.

![Shell Demo](https://img.shields.io/badge/version-1.0.0-blue)
![C++](https://img.shields.io/badge/C++-17+-orange)
![Platform](https://img.shields.io/badge/platform-Unix%20%7C%20Linux%20%7C%20macOS-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)

## Features

### Core Shell Features
- **Interactive prompt** with current working directory display
- **Command execution** for any program in `$PATH`
- **Argument handling** with proper space separation
- **Error handling** with descriptive messages

### Advanced Tokenizer
- **Quote support** - `echo "hello world"` treated as single argument
- **Escape sequences** - `echo hello\ world` joins arguments
- **Mixed quotes and escapes** - `echo "quoted \"text\""` works correctly
- **Multiple spaces** - Collapsed intelligently

### Built-in Commands
| Command | Description | Usage |
|---------|-------------|-------|
| `cd` | Change directory | `cd [path]` (defaults to `$HOME`) |
| `pwd` | Print working directory | `pwd` |
| `exit` | Exit the shell | `exit` |

### Architecture

┌─────────────────────────────────────────────────────────┐
│ KShell Loop │
├─────────────────────────────────────────────────────────┤
│ Prompt → Read → Tokenize → Built-in? → Fork/Exec → Wait │
└─────────────────────────────────────────────────────────┘
### Learning Objectives
- This project was built to understand:

- Process Management - fork(), exec(), wait()

- String Parsing - State machines, tokenization

- System Calls - chdir(), getcwd(), execvp()

- Shell Internals - Built-in vs external commands

- C++ Design - Modular architecture, headers

- Unix Philosophy - Parent-child process relationships

## Building KShell

### Prerequisites
- C++17 compatible compiler (g++ or clang++)
- Unix-like operating system (Linux, macOS, WSL)
- `make`

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





### Limitations & Future Work
Current Limitations
No pipe support (|)

No redirection (>, <, >>)

No background jobs (&)

No command history

No tab completion

No variable expansion ($HOME, $PATH)

Physical paths only (no symlink awareness)

