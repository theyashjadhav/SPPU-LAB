import os

# Clear the terminal screen
os.system("cls")

# Print script information
print("File Recovery Script")
print("By Girija chiddarwar For Programing Wonders")

# List available drives
os.system("wmic logicaldisk get caption")

# Ask user to enter the drive letter for recovery
devname = input("Enter the drive letter to be used (e.g., C:)\n")

# Ask user to enter the name of the image file
imgname = input("Enter the image name with .img extension\n")

# Create a disk image using 'dd' command (if you have a dd-like utility on Windows)
os.system(f"dd if={devname} of={imgname} bs=512")

# Install and run 'testdisk' to recover deleted partitions and files
os.system("testdisk " + imgname)

# Inform user that the recovery process is completed
print("File recovery process completed.")
