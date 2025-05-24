Q1. Each process uses 100% of CPU utilization while it's running, because they run in turn.

Q2. It takes as long as the sum of the first and second task durations, because the first process fully uses the CPU during its execution. The second one has to issue the I/O task after it.

Q3. Yes. While the first process is waiting for the completion of an I/O task after requesting it, the second process can use the CPU.

Q4. The execution time is the same as Q2's answer, because it blocks the CPU while performing an I/O task.

Q5. The execution time is the same as Q3's answer, because it doesn't block the CPU while waiting for an I/O task.

Q6. No. After the first process's I/O task, the CPU tasks of three processes run in turns. The first one's later I/O task is delayed for a long time.

Q7. After the first process's I/O task, it has a chance to request another I/O task. So the CPU tasks of three processes can run simultaneously alongside it. It's a very good idea to give a process a chance to check if there's another I/O task.

Q8. For the "-I" option, there's no significant difference in overall running time. If the two processes are performing different tasks, a slight performance improvement can be observed.
For the "-S" option, there's a substantial difference in execution time. When one process is waiting for the I/O task  to complete, the others can continue using the CPU.
