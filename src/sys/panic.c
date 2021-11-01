void panic() {
	clear_screen();
	print_color_string("ViniuxOS System Error!", RED);
	vga_index = 80;
	print_color_string("-----------------------------------------------------------------------", RED);
	vga_index = 240;
	print_color_string("A System Error occured, causing ViniuxOS to crash. The computer will restart.", RED);
	vga_index = 320;
	print_string("Rebooting.....");
	reboot();
}
