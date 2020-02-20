# Lua Lab

In this experiment, we compile `Lua` into a C++ executable and call a `Lua` function from native code.

The `Lua` source code is not provided in this repository, but cloned during the build step. This is dony by CMake with `ExternalProject`, see: [CMakeLists.txt](CMakeLists.txt).

Configure and build via CMake (v3.6+), like so:

```cmake
mkdir _build
cd _build
cmake ..
cmake --build .
```

This builds an executable `lua-lab`. The Output of  `lua-lab`, if everythings works:

    0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0
    0.0 0.0 0.0 0.7 1.1 1.2 1.1 0.7 0.0 0.0 0.0
    0.0 0.0 0.9 1.7 2.2 2.4 2.2 1.7 0.9 0.0 0.0
    0.0 0.7 1.7 2.5 3.1 3.2 3.1 2.5 1.7 0.7 0.0
    0.0 1.1 2.2 3.1 3.6 3.8 3.6 3.1 2.2 1.1 0.0
    0.0 1.2 2.4 3.2 3.8 4.0 3.8 3.2 2.4 1.2 0.0
    0.0 1.1 2.2 3.1 3.6 3.8 3.6 3.1 2.2 1.1 0.0
    0.0 0.7 1.7 2.5 3.1 3.2 3.1 2.5 1.7 0.7 0.0
    0.0 0.0 0.9 1.7 2.2 2.4 2.2 1.7 0.9 0.0 0.0
    0.0 0.0 0.0 0.7 1.1 1.2 1.1 0.7 0.0 0.0 0.0
    0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0
