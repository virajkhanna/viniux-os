#define BACKSPACE 0x0E
#define ENTER 0x1C
#define IRQ1 33

void init_keyboard();

static char key_buffer[256];

#define SC_MAX 57
const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
        "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
        "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
        "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
        "/", "RShift", "Keypad *", "LAlt", "Spacebar"};
const char sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
        'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
        'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
        'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '};
        
void print_letter(uint8_t scancode) {
    switch (scancode) {
        case 0x0:
            print_string("ERROR");
            break;
        case 0x1:
            print_string("ESC");
            break;
        case 0x2:
            print_string("1");
            break;
        case 0x3:
            print_string("2");
            break;
        case 0x39:
            print_string("Space");
            break;
        default:
            if (scancode <= 0x7f) {
                print_string("Unknown key down");
            } else if (scancode <= 0x39 + 0x80) {
                print_string("key up ");
                print_letter(scancode - 0x80);
            } else {
                print_string("Unknown key up");
            }
            break;
    }
}


static void keyboard_callback(registers_t *regs) {
    uint8_t scancode = port_byte_in(0x60);
    print_letter(scancode);
}

void init_keyboard() {
   register_interrupt_handler(33, keyboard_callback); 
}
