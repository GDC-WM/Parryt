# Project Parry
- A platformer game to show that we can in fact successfully code things (using C++ and the SFML graphics library).

- Will involve a satisfying parrying mechanic.


## Install on Linux:

- Install cmake, g++, SFML, git, and SFML-dev from your package manager (specific names depend on your distribution)
- Run the following commands from within the directory you would like the game to be:
1. ```git clone https://github.com/aaronamk/WM-GDC-Project-Parry.git```
2. ```mkdir WM-GDC-Project-Parry/Release```
3. ```cd WM-GDC-Project-Parry/Release```
3. ```cmake ..```
4. ```make```
5. ```./application_layer.exe```


## Install on Windows:

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
