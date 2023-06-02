# ViniuxOS
ViniuxOS is my own operating system. Currently, it does nothing but boot and print some text. It is an x86 32 bit OS which runs only on legacy bios currently. If you can contribute, please open a pull request or an issue and contribute!

PLEASE EXPERIMENT WITH VINIUX OS AT YOUR OWN RISK. I AM NOT RESPONSIBLE FOR ANYTHING.

## Requirements
- CPU - Anything 200 mhz or higher, 32-bit/64bit
- RAM - 256 MB+
- DISK - 20MB+
- KEYBOARD - IBM P/S 2 or better

## How to build ViniuxOS
### Linux and WSL
On Linux and WSL, first install some packages (this is for Debian/Ubuntu based linux distributions)
```
sudo apt install build-essential gcc make grub-common xorriso nasm gcc-multilib grub-efi genisoimage mtools
```
Then run,
```
make
```
ViniuxOS should automatically build and there will be an updated ISO called kernel.iso in the bin directory.
### Windows
It is highly recommended that you build ViniuxOS in WSL if you have Windows. Currently there is no way to build ViniuxOS in Windows without WSL. Support for cgywin and msys64 will come soon

### Features to be implemented

- Shell
- GUI (Maybe..)
- Shutdown
- 64 bit implementation

### Feature development in progress

- UEFI GRUB Boot
- Keyboard Driver

### Features implemented

- Legacy BIOS Boot
- Screen Driver
