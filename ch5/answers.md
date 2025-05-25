# Homework(Simulation)

Q1.

```
Action: a forks b
a - b

Action: a forks c
a - b
  - c

Action: c EXITS
a - b

Action: a forks d
a - b
  - d

Action: a forks e
a - b
  - d
  - e
```

Q2. A higher `fork_percentage` means more frequent process creation via `fork()`, which leads to a more intricate process tree structure.

Q3.

```
                           Process Tree:
                               a

Action? a forks b
                               a
                               └── b
Action? a forks c
                               a
                               ├── b
                               └── c
Action? b forks d
                               a
                               ├── b
                               │   └── d
                               └── c
Action? d forks e
                               a
                               ├── b
                               │   └── d
                               │       └── e
                               └── c
Action? e EXITS
                               a
                               ├── b
                               │   └── d
                               └── c
```

Q4. Just Before `c` exits, the process tree looks like this:

```
a
└── b
    └── c
        └── d
        └── e
```

When `c` exits without `-R` option, `d` and `e` arereparented to the init prcess, `a`:

```
a
└── b
└── d
└── e
```

However, if the `-R` option is used, `d` and `e` are reparented to their nearest living ancestor, which is `b` in this case:

```
a
└── b
    └── d
    └── e
```

Q5.

```
                           Process Tree:
                               a

Action: a forks b
Action: b EXITS
Action: a forks c
Action: c forks d
Action: c forks e

                        Final Process Tree?
                              a
                              └── c
                                  └── d
                                  └── e
```

Q6. No, the order of actions isn't generally deterministic. However, if a newly created child process immediately performs a forks as its first action, then the resulting behavior becomes deterministic, as the sequence is fixed and predictable.

```
                           Process Tree:
                               a

Action? a forks b
Action? b forks c
Action? c forks e
Action? c forks f
Action? a forks d

or

Action? a forks b
Action? b forks c
Action? c forks e
Action? a forks d
Action? c forks f

                        Final Process Tree:
                               a
                               ├── b
                               │   └── c
                               │       ├── e
                               │       └── f
                               └── d
```

# Homewrok(code)

All codes are in **./homework**.

Q1. Each process has its own memory space, so variables with the same name in each process are different. Setting a value in one process has no effect on the variable in the other.

Q2. After fork(), two processes may have file descriptors with the same integer value, each referring to the same Open File Table Entry.
Because this entry holds shared metadata such as the file offset and access mode, and points to the file's vnode, both processes can perform concurrent writes to the same file.

Q3. You can ensure that the child process prints first by using a pipe().
Create a pipe, which provides a read and a write end.
The child process should write a signal to the pipe after printing,
and the parent process should wait by reading from the pipe.
This way, the parent’s print will always occur after the child’s.

Q4. Each `exec()`'s postfix shows its behavior.

- `l` means that the function takes arguments as a list of variadic arguments, not as a vector(array).
- `v` means that the function takes arguments as a vector, not as a list(ariadic arguments).
- `e` means that the function uses the custom environment variables, not the system's.
- `p` means that the function searches in `PATH` if the path is the realtive one.

Maybe the reason why there are so many variants of the same bacsic call is to provide programmers with flexibility and control.

Q5. The `wait()` call in a parent process returns the PID of its the first terminated child.
It's meaningless to call `wait()` in a child process. The wait call in a child process returns immediately with `-1` and sets `errno` to `ECHILD`. The `ECHILD` error code means the process has no child processes to wait for.

Q6. `waitpid()` is more powerful than `wait()`. It allows the parent to wait for a specific child process, control the waiting behavior(e.g., avoid blocking), and optionally collect resource usage statistics via `rusage`.

Q7. Nothing is shown after closing `STDOUT_FILENO`.

Q8. refer to the source file.
