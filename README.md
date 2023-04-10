# HotFreeze
![alt text](https://github.com/xXxpapusasxXx/HotFreeze]/blob/image.ppg)

Are you tired of Deep Freeze preventing you from modifying your system as you wish? Do you want to install or uninstall programs without having to thaw your hard drive every time? Would you like to have complete control of your PC without losing security and performance? Then you need this program. It is a tool that allows you to disable the Deep Freeze program quickly and easily.

# How works?
The program operates as follows: from a USB drive with Ubuntu installed on it, you run the program and it detects which disks contain the Windows system and makes some changes to disable Deep Freeze from the outside. (The Ubuntu system used for testing was the same one used for installation.)

# Explanation of the code
The program starts by printing a message ‘HotFreeze for @rocopolas’. Then, it creates an empty list of strings called ‘discs’ and defines some string variables to store paths and file names.
Next, the program opens a specific directory in the file system, which is the path ‘/media/ubuntu/’. If successful, it uses the C++ filesystem library to iterate through the files in the directory and add the names of the discs to the ‘discs’ list.
Next, the program iterates through each disc in the ‘discs’ list and checks if it contains a ‘/Windows’ directory. If it does, it prints a message indicating that Windows has been found on that disc. Then, it renames the file ‘DeepFrz.sys’ in the path ‘/Windows/System32/’ to ‘Hotfreeze.sys’. After that, it makes a copy of the file ‘cdrom.sys’ in the same path and renames it as ‘DeepFrz.sys’.
Finally, the program ends and returns an exit code of 0, indicating that it has completed successfully.
