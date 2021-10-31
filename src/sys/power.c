void reboot() {
  __asm__("JMP 0xFFFF");
}

void shutdown() {
	__asm__("hlt");
}
