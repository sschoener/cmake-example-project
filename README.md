# C/CPP with CMake - example project
This is an example project that illustrates how to use CMake >= 3.14 with C. The setup that I am assuming is the following:
 * Our program consists of three parts:
    * a library (myLib) living in `myLib`,
    * an application (myApp) living in `myApp` using that library,
    * tests for the library living in `myLibTest`.
 * We do not use an external library for testing but want to write the unit tests on our own.
 * We are only interested in getting our project to compile/run/pass tests. This repository does not cover installation/deployment.

## Usage
The main purpose of this repository is educational. Start by reading `CMakeLists.txt` from this repository. It is heavily commented and will point you to other files. Once you are done with this, here is how to actually execute the code:

 1. Create a directory `build` (or any other name, really, but this is the name chosen by convention) to contain all of the files build by CMake plus some of its metadata and caches:
    ```
    mkdir build
    ```
 2. Switch to the directory and execute `cmake ..` which will tell CMake to take the source from the parent directory and use the current directory as the build directory:
    ```
    cd build
    cmake ..
    ```
    You should see some output from CMake, telling you what compiler it is using etc. CMake will choose a sensible default build system to produce build scripts or similar for. Usually, this is either `make`, Visual Studio, or XCode. You can change this by using
    ```
    cmake .. -G"Ninja"
    ```
    for example. Visit [this page](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) for more information.
 3. Create a build from there with the build system that you have chosen. For make, this is simply a case of running
    ```
    make
    ```
 4. Run the tests by using `ctest`:
    ```
    ctest
    ```
    This will show you the status of your tests.

### TL;DR for `make`
```
mkdir build
cd build
cmake ..
make
ctest
```
