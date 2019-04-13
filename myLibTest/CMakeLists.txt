# This is the CMake file for the tests in this folder. You should have
# arrived here coming from the end of the top-level CMakeLists.txt file.

# Add an executable build target for the tests. This will be used to build the
# executable that actually runs the code.
#  
# Find more information here:
#   https://cmake.org/cmake/help/latest/command/add_executable.html
add_executable(mylibTest)

# Add the sources as before.
target_sources(mylibTest
    PRIVATE 
        main.c
)

# The test executable will of course depend on the library that we actually
# want to test. Note that `PRIVATE` is specified to indicate that whoever might
# depend on this build target should not also depend on `mylib` (although it
# is unlikely that someone depends on the tests, it is still good practice).
#
# Find more information here:
#  https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(mylibTest PRIVATE mylib)

# Add the executable that we have just created as a test. This instructs CTest
# to include it when running tests.
#
# Find more information here:
#  https://cmake.org/cmake/help/latest/command/add_test.html
add_test(myTest mylibTest)