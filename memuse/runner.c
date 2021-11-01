// Mel Krusniak
// Tester file for memuse system call

#include <unistd.h>
#include <sys/syscall.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void increase_heap_active(int s) {
	char * a = malloc(s);
	for(int i = 0; i < s; i++) a[i] = 'a';
}

void increase_heap_passive(int i) {
	malloc(i);
}

void increase_stack(int i) {
	if(i > 0) increase_stack(i-1);
}

int main(int * argc, char ** argv) {
	// Here are some values that we should remember to test the call:
	// Our syscall happens to be #442.
	// Its first argument is a PID.
	// Its second argument is 1 for call stack, 2 for kernel stack, and 3 for the heap.

	// We start by doing some meaningless exercise to make our process
	//    have some associate memory to be detected in Part 4.


	// Part 4: Add some relevant memory, as desired
	// increase_heap_passive(20000);
	// increase_heap_active(20000);
	// increase_stack(20000);

	// Part 3: Execute a system call explicitly
	// asm("movq $0, %rdi");
	// asm("movq $1, %rsi");
	// asm("movq $442, %rax");
	// asm("syscall");

	// Part 2 (and 4): Use syscall function
	pid_t p = getpid();
	printf("Own PID: %d\n", p);
	printf("%ld\n", syscall(442, p, 1));

}

