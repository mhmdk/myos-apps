#include"syscalls.h"

int print(char *s) {
	return syscall(syscall_print, &s);
}

int sleep(uint32_t milliseconds) {
	return syscall(syscall_sleep, &milliseconds);
}

int exit(int status) {
	return syscall(syscall_exit, &status);
}
int getpid() {
	return syscall(syscall_getpid, 0);
}
