# Directory Spill Utility
Moves the contents of each directory in the current directory to the current directory.

The utility is intended for use on Windows or Linux.

Uses C++'s filesystem header.

# Prerequisites
__For Windows, Mingw-w64 is required to compile and / or run the program.__

To install Mingw-w64, follow steps 3 and 4 under the 'Prerequisites' section of the following document, which are also listed below:  
https://code.visualstudio.com/docs/cpp/config-mingw  

1. Proceed to https://www.msys2.org/.
2. Follow the instructions under the red "Installation" header beginning with downloading the MSYS2 installer. For clarity, some of those instructions have been mirrored below.
3. Once the MSYS2 terminal has opened automatically, run the following command:  
   `pacman -Syu`  
   _Note that this may take a minute..._

4. Once the MSYS2 terminal closes, use the Windows Start menu to search for and open "MSYS2 MSYS".
5. Once the MSYS2 terminal has opened, run the following command:  
   `pacman -Su`  
    _Note that this may take a minute..._   
6. To install mingw-w64, run the following command:  
   `pacman -S --needed base-devel mingw-w64-x86_64-toolchain`  
   _Note that this may take a minute..._   
7. Now that Mingw-w64 is installed, it must be added to the windows `PATH` environment variable. To do so, begin by making note of the path to Mingw-w64's `bin` folder. By default it is `C:\msys64\mingw64\bin`.
8. Search "Edit the system environment variables" in the Windows Start menu and select the entry of the same name.
9. Click the "Environment Variables..." option.
10. Find the variable labeled "Path", click the entry, and then click the "Edit..." button.
11. Click the "New" button and paste in the Mingw-w64 path found in step 7.
12. Select OK to confirm. Close and reopen any active console windows.


# Compilation
## ___Windows___
Open Command Prompt in the repository's directory and run the following:

`make`

To cleanup, run:

`cleanup`

## ___Linux___
Open Terminal in the repository's directory and run the following:

`make`

To cleanup, run:

`make clean`

# Usage

When invoked, the program moves the contents of each directory in the current directory to the current directory. Merges conflicting folder names.

For example, when run in `C:/Example/Folder`, the program will create move the contents of subdirectories `C:/Example/Folder/sub1`, `C:/Example/Folder/sub2`, etc, to `C:/Example/Folder`. Therefore, `C:/Example/Folder/sub1/note.txt` will move to become `C:/Example/Folder/note.txt`.

__WARNING: The original subdirectories will not exist after this operation!__ In the above example, this means that `C:/Example/Folder/sub1`, `C:/Example/Folder/sub2`, etc, will no longer exist.
___
## ___Windows___
1. Either compile the executable ___or___ download from the releases page.

2. Place the executable inside the directory to be copied.
  
The command line invocation includes two optional arguments, the absolute path to the output and absolute path to the input.

Note that command line arguments can be used by either opening Command Prompt and using the command line invocations as listed below, or by making a shortcut to the executable, right-clicking the shortcut, clicking `Properties`, and adding the arguments in the `Target:` field after `.exe`.

If the executable is downloaded and run directly, the program will use the default, no command line arguments invocation.

### Command Line Usage `{Required} [Optional]`
_via Command Prompt_

`spill [Directory to Spill] [Directory to Spill Into]`

Note: Defaults to spilling all directories in the current directory into the current directory.


## ___Linux___
1. Compile the executable.

2. Place the executable inside the directory to be copied.
  
The command line invocation includes no optional arguments.

### Command Line Usage `{Required} [Optional]`
_via Terminal_

`spill [Directory to Spill] [Directory to Spill Into]`

Note: Defaults to spilling all directories in the current directory into the current directory.


# Licensing

    Copyright (C) 2021  Mit Bailey

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.