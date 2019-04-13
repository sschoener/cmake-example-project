# This is the CMake file for the library in this folder. You should have
# arrived here coming from the end of the top-level CMakeLists.txt file.

# Add a library as a build target. This directive says that we want a static
# library named `mylib`. We will specify the source files used in that library
# further down. 
# Build targets in CMake are added via either `add_library` or via
# `add_executable`. Each build target will be available to be build later in
# the generated actual build scripts. Build targets can have properties
# attached to them, such as what source files are related to them, what
# includes they offer, their dependencies etc.
# It is generally preferred to bind any sort of information to a build target
# instead of having it in a globally available variable, so make sure to 
# always check whether there is a command starting with `target_` available.
#
# Find more information here:
#  https://cmake.org/cmake/help/latest/command/add_library.html
add_library(mylib STATIC)

# We need to collect all files to compile for the library that we have just
# added. This sets the `SOURCES` property of the `mylib` build target.
#
# Note that we could also have included the source files in the call to
# `add_library`, but this here is more explicit and hence my recommendation.
# Note the usage of `PRIVATE` here, which specifies that the sources are not
# visible to other build targets.
#
# When you have more files, this could look like this instead:
#
#   target_sources( mylib
#       PRIVATE
#           src/library.c
#           src/fileA.c
#           src/fileB.c
#   )
#
# Find more information here:
#  https://cmake.org/cmake/help/latest/command/target_sources.html
target_sources( mylib
    PRIVATE
        src/library.c
)

# Finally, let's specify the include directories used by the library. There are
# three different kinds of includes that we might want to specify:
#  * PRIVATE includes -- these are includes that are visible to this build 
#    target.
#  * INTERFACE includes -- these are includes that are visible to every other
#    build target that depends on this target.
#  * PUBLIC includes -- this is a combination of PRIVATE and INTERFACE.
# These three kinds actually make sense for build target properties in general
# and hence permeates through all of CMake.
# In our case, we do not need INTERFACE-only includes, so they are not
# specified. 
# This will specifc that the `include` directory is available publicly where as
# anything in `src` is available to be included from inside the library.
target_include_directories( mylib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
