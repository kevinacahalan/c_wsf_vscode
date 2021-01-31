## This is a pre-made workspace folder for C programming on Visual Studio Code
This workspace folder works on Mac, Windows, and Linux. Both debugging and compiling work properly. Make sure you read the prerequisite steps below before trying to use this thing. To use this workspace folder open it as your highest folder in Visual Studio Code. To add a program to this workspace folder make a subfolder to put its source files in. After finshing the prerequsite setup stuff things should magically work. In the future when there is more time I will make a few similar workspace folders, one for C++ and one that uses makefiles.

- How to download:

![how_to_download.png](https://cdn.discordapp.com/attachments/750174753372766280/794445866790289428/how_to_download.png)


## How to use

- To Build:
Select any source file in the program folder of the program you want to debug and then hit the keys `CTRL + SHIFT + B`.

- To Debug:
Place a breakpoint were you want the debugger to start debugging and then hit the `f5` key.
If your program takes command line arguments hardcode those args into the args section in the launch.json file. If you want to find where your program crashes run the debugger without placing a breakpoint.

- To Run a Program:
After successfuly building there should be an executable with the same name as the folder it was compiled placed in the folder that is was compiled in. On Mac or Linux this excuatable would be called `program_folder_name`, on Windows `program_folder_name.exe`. To run the executable right-click on it and pick the option "Open in Integrated Terminal". Next if you are on Mac or linux run `./program_folder_name`, on Windows `.\program_folder_name`.


## Prerequisite setup stuff

 
For this workspace folder to work YOU MUST HAVE gcc & gdb on your path.
	
You must also have the C/C++ VScode extention from microsoft installed.	
Uninstall any other extension having to do with C/C++ as these extentions	
might fight with the one from Microsoft, exp the extension from Austin, or
that extension called "CodeRunner"...	

You must also have your Workspace folder structured to have a	
separate sub-folder for each program you want to compile. Each
program-folder can only have one source file with a main() function.
	
	
### How to get gcc & gdb on your PATH:
 
* Windows:

  * Download mingw-w64 gcc/gdb from http://mingw-w64.org/doku.php/download/mingw-builds
  * Next run the installer and install mingw-w64 at the default location or some location you won't forget.
  * Next add mingw-w64 to the PATH.
  * For a detail guild on this: (read steps 3 and 4)https://code.visualstudio.com/docs/cpp/config-mingw
  
  After putting mingw-w64 on the path restart VScode so that it gets an updated PATH.
	
  
* Linux & Windows Subsystem for Linux:

  * Debain based install:
  
    `sudo apt-get update`
    
    `sudo apt-get install gcc gdb make`

  * Arch based install:
  
    `sudo pacman -Syu`
    
    `sudo pacman -Sy gcc gdb make`

  After installing gcc & gdb restart VScode so that it gets an updated PATH.


* Mac:

  * To install: `xcode-select --install`
  * After installing restart VScode so that it gets an updated PATH, you might need to re-login.
  * The `xcode-select --install` command actually installs clang & lldb, not gcc & gdb.
On mac if you have clang installed the gcc command runs clang, don't worry
about this sense the two compilers for your proposes are probably the same.
If you really want gcc this video shows you how: https://www.youtube.com/watch?v=0z-fCNNqfEg


To check if you successfully got gcc & gdb on your path	run `gcc -v` and `gdb -v`


### Windows Subsystem for linux
It is possible to get a very nice setup where you can easly change between compiling and debuging on native windows and WSL.
This setup is the most optimal for windows users sense it's very useful you to have easy access to some very powerful Unix exclusive tools.
I do not feel like typing up the instructions to get this setup working, but hopfully will at some point. In genreal the additional things you have to do are, install WSL, install the WSL extention, click on the green button in the lower left then select `Remote-WSL: Reopen folder in WSL`, then install the C/C++ extention a second time while VScode is in WSL mode.



## Rules of use
- Do not have more than one source file with a main() function in the same program folder.
- Do not put this workspace folder inside a workspace folder, in other words do not have this workspace folder be a subfolder. This workspace folder must be the highest folder open in VScode for it to work.
- A program folder should be a subfolder of this workspace folder, do not nest program folders as this might cause activity that might confuse you.
- Do everything specified in the prerequisite setup setups...
- If stuff is not working before complaining or giving up double check and make sure you have the Coderunner extention not installed.
- On Linux and probably Mac you can not run programs on a normal USB stick without doing some odd stuff. In other words if you have this workspace folder on a USB stick take it off before using it with Linux or Mac.

## Known Issues
- On Mac sometimes the compiler puts the excutable in an odd spot thus causing the debugger problems.
- TDM-gcc gcc does not work and will give the error `gcc: error: *.c: Invalid argument `
- One windows there is no way to detect if you are using a the linux subsystem wsl from VScode started from native windows. To make things work start VScode from the subsystem console window using the command `code`. You will also have to install the WSL extension....<--I am partly wrong, will write up currect instructions on how to setup WSL at some point.

If you find an issues that can be fixed or improved submit a pull request
