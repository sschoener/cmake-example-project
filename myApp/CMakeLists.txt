# This is the CMake file for the app in this folder. You should have
# arrived here coming from the end of the top-level CMakeLists.txt file.

# The following commands work exactly as in the case for tests. See the
# CMakeLists.txt file there for further explanation.

add_executable(myApp)
target_sources(myApp
    PRIVATE 
        main.c
)
target_link_libraries(myApp PRIVATE mylib)
