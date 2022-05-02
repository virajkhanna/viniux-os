bits 32

section .multiboot               
        dd 0x1BADB002            
        dd 0x0                   
        dd - (0x1BADB002 + 0x0)

section .text
global start
extern kmain
%include "src/cpu/interrupts.asm"

start:
	cli
	sti
	mov esp, stack_space
	
	;Enable A20 Gate
	
	in al, 0x92
	or al, 2
	out 0x92, al
	
	call kmain ; Jump to the kernel
	jmp $

section .bss
resb 100000 ; 100kb for the stack
stack_space:
