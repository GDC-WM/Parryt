## DESCRIPTION
* A platformer game following Pari the parrot man, defender of... parrots.
* Contains a satisfying parrying mechanic.
* Uses C++, the SFML graphics library, and the Box2D physics engine
* General class hierarchy: `UserView <- GameController <- GameState <- View <- Model <- Actor`
![Demo Screenshot](resources/parryt-screenshot.png)


## BUILD/RUN (from source)
Dependencies: make, cmake, gcc, sfml, box2d

### Linux
Arch/Manjaro:
```shell
sudo pacman -S cmake make gcc box2d sfml git
git clone https://github.com/GDC-WM/Parryt.git
mkdir Parryt/Debug
cd Parryt/Debug
cmake ..
make
./parryt
```

Other:
* Install make, cmake, gcc, SFML (libsfml-dev on Ubuntu) (and possibly SFML-dev), randr (xorg-dev and libglu1-mesa-dev on Ubuntu), doxygen, and git from your package manager (specific names depend on your distribution.
* Clone the repo with box2d submodule:

```
git clone --recursive https://github.com/GDC-WM/Parryt.git
```

* Build box2d:

```shell
mkdir Parryt/box2d/build
cd Parryt/box2d/build
cmake -DBOX2D_BUILD_DOCS=ON ..
cmake -build .
sudo cmake --build . --target install
cd ../../..
```

* Build/run Parryt:
```shell
mkdir Parryt/Debug
cd Parryt/Debug
cmake ..
make
./parryt
```


### MacOS
* Install Homebrew (a package manager) and follow the instructions for Linux.


### Windows

Use [this video](https://linuxconfig.org/install-manjaro-in-virtualbox) to install Manjaro in a Virtual Machine, then follow our Manjaro Linux build instructions

**WARNING**: The following alternative method doesn't work with Box2D

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
