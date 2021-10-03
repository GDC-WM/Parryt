## DESCRIPTION
* A platformer game following Pari the parrot man, defender of... parrots.
* Contains a satisfying parrying mechanic.
* Uses C++, the SFML graphics library, and the Box2D physics engine
* General class hierarchy: `UserView <- GameController <- GameState <- View <- Model <- Actor`

![Demo Screenshot](resources/parryt-screenshot.png)


## INSTALL DEPENDENCIES
Dependencies: `make`, `cmake`, `gcc`, `sfml`, `box2d`

### Linux
Arch/Manjaro:
* Run `sudo pacman -S make cmake gcc sfml box2d git`.

Ubuntu (the following are untested instructions):
* Run `sudo apt install make cmake gcc libsfml-dev sfml-dev xorg-dev libglu1-mesa-dev`
* Build box2d (see below).

Other:
* Install the dependencies listed above, plus possibly randr and sfml-dev from your package manager. Specific names for these packages depend on your distribution.
* If your package manager does not have box2d, you will have to build it.

Build box2d (only if your package manager does not have it available):
* Install `doxygen` from your package manager.
* Run:
```shell
https://github.com/erincatto/box2d.git
mkdir box2d/build
cd box2d/build
cmake -DBOX2D_BUILD_DOCS=ON ..
cmake -build .
sudo cmake --build . --target install
cd ../..
```

### MacOS
* Run `echo "export LIBRARY_PATH=\"$LIBRARY_PATH:/usr/local/lib\"" >> ~/.zshenv`. This adds a necessary line to your .zshenv file.
* Close the terminal and open a new one.
* Install [Homebrew](https://brew.sh/) (a package manager).
* Run `brew install cmake make gcc box2d sfml git`.

### Windows
* Use [this article](https://linuxconfig.org/install-manjaro-in-virtualbox) to install Manjaro Linux in a Virtual Machine.
* Follow the Arch/Manjaro instructions.


## BUILD/RUN:
* After installing the dependencies, run:
```shell
git clone https://github.com/GDC-WM/Parryt.git
mkdir Parryt/Debug
cd Parryt/Debug
cmake ..
make
./parryt
```
