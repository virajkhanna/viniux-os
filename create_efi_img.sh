BOOT_IMG_DATA=$(mktemp -d)
BOOT_IMG=$(mktemp -d)/efi.img

mkdir -p $(dirname $BOOT_IMG)

truncate -s 8M $BOOT_IMG
mkfs.vfat $BOOT_IMG
mount $BOOT_IMG $BOOT_IMG_DATA
mkdir -p $BOOT_IMG_DATA/efi/boot

grub-mkimage \
    -C xz \
    -O x86_64-efi \
    -p /boot/grub \
    -o $BOOT_IMG_DATA/efi/boot/bootx64.efi \
    boot linux search normal configfile \
    part_gpt btrfs ext2 fat iso9660 loopback \
    test keystatus gfxmenu regexp probe \
    efi_gop efi_uga all_video gfxterm font \
    echo read ls cat png jpeg halt reboot

umount $BOOT_IMG_DATA
rm -rf $BOOT_IMG_DATA

cp $BOOT_IMG ./efi.img

xorriso -as mkisofs \
    -iso-level 3 \
    -r -V ViniuxOS_v1_UEFI \
    -J -joliet-long \
    -append_partition 2 0xef efi.img \
    -partition_cyl_align all \
    -o bin/viniuxos_uefi.iso \
    iso
    
rm efi.img
