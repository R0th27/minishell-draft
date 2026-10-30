*This project has been created as part of the 42 curriculum by htoe, hsint.*

# Minishell — UNIX Shell Reimplementation in C

## Overview

**Minishell** is a systems-level reimplementation of a UNIX shell written in C as part of the 42 School curriculum.

The project recreates the core behavior of a shell such as:

```bash
$ command < infile | command > outfile
```

while implementing the underlying mechanisms directly with POSIX system calls rather than relying on an existing shell.

The implementation focuses on:

* Robust command parsing and tokenization
* Environment variable expansion
* Quote and wildcard handling
* Pipeline and process orchestration
* Precise file descriptor management
* Shell-compatible redirections
* Built-in command execution
* Signal handling in interactive and execution contexts
* Accurate exit status propagation
* Deterministic memory and resource cleanup

Rather than treating the shell as a simple command launcher, the project models the complete lifecycle of a command:

```text
Input
  │
  ▼
Lexer
  │
  ▼
Parser
  │
  ▼
Expansion / Wildcards
  │
  ▼
Execution
  │
  ├── Builtins
  ├── Pipes
  ├── Redirections
  └── External Commands
  │
  ▼
Exit Status / Shell State
```

---

## Repository Structure

```text
.
├── include
│   └── minishell.h
├── Makefile
├── README.md
└── src
    ├── builtins
    │   ├── builtins.c
    │   ├── builtins_utils.c
    │   └── env_builtins.c
    ├── execution
    │   ├── builtin_executor.c
    │   ├── exec_loop.c
    │   ├── exec_utils.c
    │   ├── executor.c
    │   ├── executor_main.c
    │   ├── path_utils.c
    │   ├── redirection.c
    │   └── redirection_utils.c
    ├── main.c
    ├── parsing
    │   ├── expand_helpers.c
    │   ├── expand_utils.c
    │   ├── expand_vars.c
    │   ├── lexer.c
    │   ├── lexer_utils.c
    │   ├── parser.c
    │   ├── parser_redir.c
    │   ├── parser_utils.c
    │   ├── token_utils.c
    │   ├── wildcard_helpers.c
    │   ├── wildcards.c
    │   └── wildcards_exec.c
    ├── signals.c
    └── utils
        └── env_utils.c
```

The project also contains a custom **libft** implementation used as a supporting library. Its internal structure is omitted here to keep the project architecture focused on the Minishell implementation itself.

---

## Architecture

The codebase is divided into independent stages:

### Input & Main Loop

`main.c`

Responsible for initializing the shell state, displaying the interactive prompt, receiving user input, and coordinating the parsing and execution lifecycle.

### Lexing

`lexer.c`
`lexer_utils.c`
`token_utils.c`

Transforms raw shell input into a sequence of meaningful tokens while respecting shell syntax such as:

* Single quotes
* Double quotes
* Pipes
* Redirection operators
* Whitespace
* Variable syntax
* Wildcard expressions

The lexer establishes the structural information required by the parser without prematurely executing commands.

### Parsing

`parser.c`
`parser_redir.c`
`parser_utils.c`

Builds executable command structures from the token stream.

Parsing is responsible for understanding relationships between:

* Commands
* Pipelines
* Arguments
* Redirections
* Input/output targets

This separates shell syntax from the execution layer.

### Expansion & Wildcards

`expand_vars.c`
`expand_helpers.c`
`expand_utils.c`
`wildcards.c`
`wildcard_helpers.c`
`wildcards_exec.c`

Handles shell expansion before execution, including:

* Environment variables
* `$?`
* Quote-aware expansion
* Wildcard matching
* Filename expansion

Expansion behavior depends on quoting context, making this stage closely tied to the lexical representation of the command.

### Execution

`executor.c`
`executor_main.c`
`exec_loop.c`
`exec_utils.c`

Coordinates command execution and process creation.

The executor determines whether a command should run as:

* A builtin in the parent shell
* A builtin inside a child process
* An external executable
* Part of a pipeline

### Redirections

`redirection.c`
`redirection_utils.c`

Implements shell redirections using file descriptor operations such as:

* `open`
* `dup`
* `dup2`
* `close`

Supported forms include:

```bash
< input
> output
>> append
<< heredoc
```

Redirection setup is performed before command execution so that each process receives the correct standard input/output streams.

### Builtins

`builtins.c`
`builtins_utils.c`
`env_builtins.c`

Implements the required shell builtins:

```text
echo
cd
pwd
export
unset
env
exit
```

Builtins that modify persistent shell state, such as `cd`, `export`, `unset`, and `exit`, require special handling when executed outside a child process.

### Signals

`signals.c`

Provides context-aware signal handling for:

* Interactive prompt state
* Child execution
* Interrupting commands
* `SIGINT`
* `SIGQUIT`

Signal behavior is changed depending on whether the shell is waiting for input or waiting for a child process.

### Environment

`env_utils.c`

Maintains and manipulates the shell environment used by:

* Variable expansion
* `export`
* `unset`
* `env`
* PATH resolution
* External command execution

---

## Functional Scope

The shell supports the core functionality expected from a UNIX shell.

### Command Execution

```bash
ls
pwd
echo hello
cat file.txt
```

### Pipelines

```bash
ls -l | grep ".c" | wc -l
```

Commands are connected through UNIX pipes, with each process receiving the appropriate standard input and output descriptors.

### Redirections

```bash
cat < input.txt
echo hello > output.txt
echo hello >> output.txt
```

### Heredoc

```bash
cat << EOF
hello
world
EOF
```

### Environment Variables

```bash
export TEST="Hello World"
echo $TEST
```

The shell also maintains the special exit-status variable:

```bash
echo $?
```

### Builtins

```bash
echo
cd
pwd
export
unset
env
exit
```

### Wildcards

Filename expansion is supported through wildcard patterns such as:

```bash
ls *.c
echo src/*.c
```

### Quoting

Commands can distinguish between single-quoted and double-quoted contexts:

```bash
echo '$USER'
echo "$USER"
```

This allows expansion behavior to depend on the quoting context, as expected from shell semantics.

---

## Execution Model

For an external command, the execution flow is approximately:

```text
Parsed Command
      │
      ▼
Apply Expansions
      │
      ▼
Resolve Redirections
      │
      ▼
Create Pipeline / Process
      │
      ▼
Configure File Descriptors
      │
      ▼
Resolve Executable via PATH
      │
      ▼
execve()
      │
      ▼
waitpid()
      │
      ▼
Update Shell Exit Status
```

For pipelines, each command is executed in its own process and connected through pipe file descriptors.

### Process Discipline

The executor carefully manages the lifecycle of:

* Child processes
* Pipe endpoints
* Input/output descriptors
* Temporary redirection descriptors
* Exit statuses

Unused pipe ends are closed as soon as they are no longer required to prevent blocked reads and hanging processes.

---

## Builtin Execution Model

Builtins require different execution semantics depending on their position in a command.

A standalone state-changing builtin such as:

```bash
cd /tmp
export TEST=value
unset TEST
```

must affect the shell process itself.

By contrast, a builtin participating in a pipeline may execute in a child process:

```bash
export TEST=value | echo hello
```

The executor therefore distinguishes between:

* Builtins executed directly by the parent shell
* Builtins executed as part of a child process
* External commands executed through `execve`

This distinction is essential for preserving shell state correctly.

---

## PATH Resolution

External commands are resolved using the shell's environment.

The resolution process:

1. Retrieves `PATH` from the environment.
2. Splits it into individual directories.
3. Constructs candidate executable paths.
4. Checks command accessibility.
5. Executes the resolved binary using `execve`.

For example:

```bash
$ echo $PATH
/usr/local/bin:/usr/bin:/bin
```

A command such as:

```bash
ls
```

is resolved by searching the configured directories until an executable candidate is found.

Commands containing an explicit path are handled separately from PATH-based lookup.

---

## File Descriptor Management

File descriptors are treated as explicit resources throughout execution.

The implementation relies heavily on:

```c
open()
close()
dup()
dup2()
pipe()
```

Typical pipeline setup resembles:

```text
       pipe
    ┌─────────┐
    │         │
cmd1 ───────► cmd2
stdout       stdin
```

Each process keeps only the descriptors it actually needs.

This prevents:

* Pipe deadlocks
* Unexpected blocking
* Descriptor leaks
* Incorrect stdin/stdout inheritance
* Broken pipeline termination

Redirections are also applied in the correct execution context so that builtin and external commands observe the same standard streams.

---

## Signal Handling

Interactive shells require different signal behavior from ordinary processes.

The implementation distinguishes between:

```text
Interactive Prompt
       │
       ▼
Waiting for User Input
       │
       └── SIGINT → refresh prompt

Running Command
       │
       ▼
Waiting for Child
       │
       └── Signals handled according to execution state
```

The shell manages signals such as:

* `SIGINT`
* `SIGQUIT`

This prevents child-process signals from incorrectly terminating the interactive shell itself while still allowing running commands to respond appropriately.

---

## Exit Status

Exit status is preserved as part of the shell's global execution state.

Examples:

```bash
false
echo $?
```

and:

```bash
ls nonexistent
echo $?
```

The executor collects child statuses with `waitpid()` and updates the shell status accordingly.

Special attention is given to:

* Builtin failures
* External command failures
* Command-not-found cases
* Signal termination
* Pipeline execution
* `exit`

The resulting status is also exposed through:

```bash
$?
```

---

## Error Handling

Error paths are designed to be explicit and deterministic.

Handled conditions include:

* Invalid commands
* Missing executables
* Invalid paths
* Permission errors
* Failed `fork`
* Failed `pipe`
* Failed `open`
* Failed `dup2`
* Invalid redirections
* Invalid builtin arguments
* Malformed syntax
* Allocation failures
* Invalid environment operations

Errors are reported without allowing partially initialized state or leaked descriptors to propagate through the execution tree.

---

## Memory Management

Memory ownership is explicitly managed across the parser and executor.

The implementation takes care to release:

* Token lists
* Parsed command structures
* Argument arrays
* Expanded strings
* Wildcard results
* Environment structures
* Temporary execution data

Cleanup paths are particularly important because Minishell contains multiple failure boundaries:

```text
Input
  ↓
Lexing
  ↓
Parsing
  ↓
Expansion
  ↓
Forking
  ↓
Redirection
  ↓
Execution
```

A failure at any stage must clean up resources created by previous stages without invalidating resources still required by active processes.

---

## Build & Usage

### Build

```bash
make
```

### Clean

```bash
make clean
```

### Full Cleanup

```bash
make fclean
```

### Rebuild

```bash
make re
```

### Run

```bash
./minishell
```

### Example

```bash
$ export TEST="Hello World"
$ echo "$TEST"
Hello World

$ ls -la | grep ".c" | wc -l

$ cat << EOF | grep hello
hello world
goodbye world
EOF
hello world
```

---

## Key Technical Skills Demonstrated

* UNIX process management with `fork`, `execve`, and `waitpid`
* Inter-process communication using pipes
* Advanced file descriptor lifecycle management
* Shell-style command parsing and tokenization
* Environment variable expansion
* Quote-aware parsing and expansion
* Wildcard / filename expansion
* Input/output redirection
* Heredoc handling
* Builtin command implementation
* PATH-based executable resolution
* POSIX signal handling
* Shell exit-status management
* Defensive memory management in C
* Multi-process execution architecture
* Modular systems programming
* Debugging of process, signal, and descriptor interactions

---

## AI-Assisted Development

AI tools were used as a **development aid**, not as a replacement for understanding or implementing the system.

Assistance was primarily useful for:

* Exploring POSIX and UNIX system-call behavior
* Reviewing edge cases in shell semantics
* Identifying potential file descriptor lifecycle issues
* Reasoning about process and pipeline behavior
* Reviewing parsing and expansion logic
* Improving code readability and documentation
* Generating test ideas for unusual execution paths
* Comparing observed behavior against expected shell behavior

All generated suggestions were reviewed, adapted, tested, and integrated according to the project's implementation requirements.

The final architecture, source code, debugging decisions, and behavior of the shell were validated through direct testing and reasoning about the underlying UNIX mechanisms.

---
