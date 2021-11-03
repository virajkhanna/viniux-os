void reboot() {
  __asm__("JMP 0xFFFF");
}

void shutdown() {
	__asm__("hlt");
	print_string("You can turn off the computer now");
}
