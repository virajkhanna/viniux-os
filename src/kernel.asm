bits 32

section .multiboot               
        dd 0x1BADB002            
        dd 0x0                   
        dd - (0x1BADB002 + 0x0)

section .text
global start
extern main

start:
	cli
	mov esp, stack_space
	call main ; Jump to the kernel
	jmp $

section .bss
resb 1000000 ; 1mb for the stack
stack_space:
