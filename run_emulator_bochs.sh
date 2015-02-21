#!/bin/bash
sudo losetup /dev/loop2 floppy.img
sudo bochs -f bochsrc.txt
sudo losetup -d /dev/loop2
