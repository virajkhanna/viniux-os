all: boot.o kernel.o kernel kernel.iso run clean

boot.o: kernel.asm
	nasm -f elf32 kernel.asm -o boot.o
	
kernel.o: kernel.c
	gcc -m32 -c kernel.c
	
kernel: kernel.o boot.o
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o
	cp kernel ../iso/boot/
	
kernel.iso: kernel kernel.o boot.o
	grub-mkrescue -o kernel.iso ../iso
	
run: 
	qemu-system-i386 kernel.iso
	
clean:
	mv *.o ../bin
	mv *.iso ../bin
	mv kernel ../bin
