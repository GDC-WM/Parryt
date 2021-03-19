# Parryt
* A platformer game following Pari the parrot man, defender of... parrots.
* Will involve a satisfying parrying mechanic.
* Uses C++, the SFML graphics library, and the Box2D physics engine

![Demo Screenshot](resources/parryt-screenshot.png)

## Install on Linux:
* Install make, cmake, g++, SFML (and possibly SFML-dev), randr (xorg-dev and libglu1-mesa-dev on Ubuntu), doxygen, and git from your package manager (specific names depend on your distribution.
* Run the following commands from within the directory you would like the game to be:
- ```git clone --recursive https://github.com/GDC-WM/Parryt.git```

building box2d (only once needed) 

- ```mkdir Parryt/box2d/build```
- ```cd Parryt/box2d/build```
- ```cmake -DBOX2D_BUILD_DOCS=ON ..```
- ```cmake -build .```
- ```sudo cmake --build . --target install```
- ```cd ../..```

building Parryt

- ```mkdir Debug``` (which makes Parryt/Debug) 
- ```cd Debug```
- ```cmake ..```
- ```make```
- ```./parryt```


## Install on Mac:
* Install Homebrew and follow instructions for Linux.

## Install on WSL (Windows Subsytem for Linux)

**Macro Steps**

1. Download WSL2 (Windows Subsytem for Linux) on Windows
2. Download a Linux distribution (At least Ubuntu 18.04 and 20.02 both worked following these steps)
3. Set up your freshly installed distribution for package downloading
4. Download specified packages above (cmake, g++, SFML...)
5. Download X11 server and configure it, allowing GUIs. 
6. Run commands starting from ```git clone...``` in the "Linux instrutions section" of the README.

**1. Download WSL2 on windows**
1. Follow https://docs.microsoft.com/en-us/windows/wsl/install-win10

**2. Download a Linux distribution**
1. If you have followed WSL2 instructions completely, you will have installed a Linux distribution like Ubuntu
2. If you have not installed a Linux Distribution, just install Ubuntu from the Windows Store 
   
**3. Set up your freshly installed distribution for package downloading**
1. Open up your distribution
2. Make a username and password as prompted, note, you won't see the password you typed for security measures
3. Run the following
- ```sudo apt update```
- ```sudo apt install sl```
- ```sl```
- If you see a steamlocomotive running through, you are good!

**4. Download specified packages above (cmake, g++, SFML...)**

```sudo apt install cmake, g++, ... as specified above```

**5. Download X11 server and configure it, allowing GUIs.**
1. Follow https://www.youtube.com/watch?v=4SZXbl9KVsw&t=153s&ab_channel=RickMakes 
2. Summary: Install VcXsrv windows x server & set a few environment variables

**6. Run commands starting from ```git clone...``` in the "Linux instrutions section" of the README.**

**Issues**
1. Ubuntu Installer raises error "The requested operation could not be completed due to a virtual disk system limitation"?
   
   Go to ```C:\Users\<your username>\AppData\Local\Packages``` and locate the folder in which your linux distribution is installed (for Ubuntu, it is CanonicalGroupLimited...). Right click => properties => advanced => uncheck compress contents to save disk space

2.  After ```sudo apt update```, ```sudo apt install <packagename>``` yields ```E: Unable to locate package <packagename>```

    Solve: first, try: ```sudo apt update -o Acquire::ForceIPv4=true```
    If no luck, do you use Symantec antivirus? If so, disable it. If it still
    doesn't work, also consult the #4139 thread listed in issue #3.
3. X11 not launching? 
    
    Solve: https://github.com/microsoft/WSL/issues/4139
    
    TLDR: open windows firewall settings, and remove WSL connection for each of the Domain, Private, and Public profiles  


## Install on Windows (possibly outdated):
**Download CMake**
1. Follow this link and go to “Download Latest Release”: https://cmake.org/
2. Under Binary distributions, download the appropriate installer for your OS. (you can install the zip file but you will have to manually add CMake to your path if you do)
3. Run the installer and make sure to check “Add CMake to Path” when you get to that point

**Download SFML and MinGW**
1. Follow this link, go to the “Download” tab, then “SFML Latest stable version” tab: http://www.sfml-dev.org
2. Click download for “GCC MinGW” 32 or 64 bit depending on your processor to download SFML.
3. Then on the same page click “MinGW Builds” 32 or 64 bit depending on your processor to download MinGW
4. Extract both of the zip files you just downloaded and put the folders into This PC > Local Disk > Program Files folder

**Add SFML and MinGW to Path**
1. For Windows, type “path” into the search bar and press enter
2. Press “Environment Variables” in the window that appears
3.  Under “System Variables” select new to create a new variable, call it INCLUDE and paste the directory to the SFML > include folder as the value
4. Do the same thing again except call the variable LIB and paste the directory to SFML > lib as the value
5. In “System Variables” scroll down, find the variable “Path”, and open it
6. Now for both SFML and MinGW, go to their respective folders in Program Files and copy the directory to their bin folders (eg. This PC > Local Disk > Program Files > SFML > bin)
7. For both bin folders, press “New” in the Path window and paste the directory
8. This process is the same for CMake if you installed the zip file

**Compile and Run Games**
1. Open the game file and create a new folder called “Debug”
2. In terminal in the Debug directory, type cmake .. -G “MinGW Makefiles” If cmake is working properly, you should see something like this:
-- The C compiler identification is GNU 7.3.0
-- The CXX compiler identification is GNU 7.3.0
-- Check for working C compiler: C:/Program Files/mingw64/bin/gcc.exe
-- Check for working C compiler: C:/Program Files/mingw64/bin/gcc.exe -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: C:/Program Files/mingw64/bin/g++.exe
-- Check for working CXX compiler: C:/Program Files/mingw64/bin/g++.exe -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found SFML .. in C:/Program Files/SFML-2.5.1/include
-- Out-source building. Build type set to: DEBUG
-- Adding executable: main
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/Zack HDoubler/source/repos/Escape-The-City/Debug
5. Then type mingw32-make If MinGW and SFML is working properly then you should see increasing percentages as the game compiles.
