// Mel Krusniak
// Tester file for memuse system call

#include <unistd.h>
#include <sys/syscall.h>
#include <stdint.h>

int main(int * argc, char ** argv) {
	// This simple example checks if a process with PID 4522 is running.

	// Part 2: Use syscall function
	// printf("%d\n", syscall(442, 4522, 1));

	// Part 3: Execute a system call explicitly
	asm("movq $4522, %rdi");
	asm("movq $1, %rsi");
	asm("movq $442, %rax");
	asm("syscall");
}
