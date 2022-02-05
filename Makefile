all: boot.o kernel.o kernel viniuxos_legacy_bios.iso clean

boot.o: src/kernel/kernel.asm
	nasm -f elf32 src/kernel/kernel.asm -o boot.o
	
kernel.o: src/kernel/kernel.c
	gcc -m32 -c src/kernel/kernel.c -o kernel.o
	
kernel: kernel.o boot.o
	ld -m elf_i386 -T src/kernel/linker.ld -o kernel.bin boot.o kernel.o
	cp kernel.bin iso/boot/
	
viniuxos_legacy_bios.iso: kernel.bin kernel.o boot.o
	grub-mkrescue -o viniuxos_legacy_bios_v1.0.iso iso
	
clean:
	mv *.o bin
	mv *.iso bin
	mv kernel.bin bin
