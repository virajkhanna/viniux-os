# ViniuxOS
ViniuxOS is my own operating system. Currently, it does nothing but boot and print some text. It is an x86 32 bit OS which runs only on legacy bios currently. If you can contribute, please open a pull request or an issue and contribute!

## How to build ViniuxOS
### Linux and WSL
On Linux and WSL, first install some packages (this is for Debian/Ubuntu based linux distributions)
```
sudo apt install build-essential gcc make grub-common xorriso nasm qemu qemu-system
```
Then run,
```
cd src
make
```
ViniuxOS should automatically build and open in a virtual machine.
### Windows
It is highly recommended that you build ViniuxOS in WSL if you have Windows. If you do not want to use WSL, then download mingw64 and build ViniuxOS (this is an untested way to build ViniuxOS, if you receive any errors while building ViniuxOS, make a Linux virtual machine or use WSL)

### Features to be implemented

- UEFI Grub Boot
- Keyboard Driver
- Shell
- GUI (Maybe..)
- Shutdown
- 64 bit implementation

### Features implemented

- Legacy BIOS Boot
- Print Driver
