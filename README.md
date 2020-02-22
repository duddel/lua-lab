# Lua Lab

In this experiment, we compile `Lua` (v5.3.5) into a C++ executable and call a `Lua` function from native code.

The `Lua` source code is not provided in this repository, but cloned during the build step. This is done by CMake with `ExternalProject`, see: [CMakeLists.txt](CMakeLists.txt).

Configure, build and test via CMake (v3.6+), like so:

```cmake
mkdir _build
cd _build
cmake ..
cmake --build .
ctest -V
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

## Lua (v5.3.5) License

    Copyright (C) 1994-2018 Lua.org, PUC-Rio.

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
