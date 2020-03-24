# Activating C++ 11
set(CMAKE_CXX_STANDARD 11)
# Sets C++ 11 standard as required for compilers
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Disable compiler-specific C++ language extensions
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(exercise exercise.cpp)
