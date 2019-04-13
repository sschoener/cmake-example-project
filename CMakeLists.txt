# This is the main entry point for CMake. Follow the comments below to get
# a better understanding of what is happening.


# This sets the minimum cmake version required. The FATAL_ERROR option forces
# some really old CMake versions to fail instead of just emiting a warning.
# 
# Find more information here:
#  https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# This sets up the project. We're giving it a name, a version, a description,
# a URL, and what languages to use. The usual languages to use are
#  * C (for plain C),
#  * and CXX (for C++).
# The project command also sets some variables for the project that we can 
# ignore for now.
# 
# Find more information here:
#  https://cmake.org/cmake/help/latest/command/project.html
project("myLib"
        VERSION 0.1.0
        DESCRIPTION "A library of sorts"
        LANGUAGES C 
)

# CMake allows you to output debug information during the build process.
# Here, we are outputting the value of the variable PROJECT_SOURCE_DIR that
# was set by the `project` directive above.
# This line is, of course, completely unnecessary, so you can safely remove it.
message("Set project source dir: ${PROJECT_SOURCE_DIR}")

# This enables the CTest module of CMake. It allows you to easily add tests to
# your project and report the results back to a build server, if needed. We
# will not be making use of the latter feature here.
#
# Find more information here:
#  https://cmake.org/cmake/help/latest/module/CTest.html
include(CTest)

# This tells CTest that we are actually want to run tests. This directive needs
# to be in the top-level CMake file (this one).
enable_testing()

# Now we will set up some compiler options. The assumption is that we are
# either using Clang/GCC or MSVC. The flags have two effects:
#  * enable all (or at least a reasonable amount of) warnings,
#  * treat every warning as an error.
if (MSVC)
        # Sets compile options for this directory and all subdirectories.
        add_compile_options(/W4 /WX)
else()
        add_compile_options(-W -Wall -pedantic -Werror)
endif()

# This adds the directives from the CMakeLists.txt files from the given
# subdirectories. Go there now to read them.
add_subdirectory(myLib)
add_subdirectory(myLibTest)
add_subdirectory(myApp)