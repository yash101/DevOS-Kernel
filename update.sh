#!/bin/bash
sudo losetup /dev/loop2 floppy.img
sudo mount /dev/loop2 /media/yoshi/kernel_floppy
sudo cp kernel_binary /media/yoshi/kernel_floppy/kernel
sudo umount /dev/loop2
sudo losetup -d /dev/loop2
