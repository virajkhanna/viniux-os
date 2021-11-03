bits 32

section .multiboot               
        dd 0x1BADB002            
        dd 0x0                   
        dd - (0x1BADB002 + 0x0)

section .text
global start
extern kmain

start:
	cli
	mov esp, stack_space
	call kmain ; Jump to the kernel
	jmp $

section .bss
resb 100000 ; 100kb for the stack
stack_space:
