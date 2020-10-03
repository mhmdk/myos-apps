# Applications for [myos](https://github.com/mhmdk/myos)

those are small programs to test multitasking and system calls implementations on [myos](https://github.com/mhmdk/myos)  
the main thing is [syscall.asm](syscall.asm) pushing syscall number and address of the first parameter to the stack  
[syscalls.c](syscalls.c) is a wrapper around assembly for different syscalls like print, sleep, exit, and getpid  