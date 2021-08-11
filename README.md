# Lua Lab

In this experiment, we

-   compile `Lua` (v5.3.5) into a C++ executable and call a `Lua` function from native code,
-   do the same thing with `LuaJIT` (2.1.0-beta3).

The `Lua` source code is not provided in this repository, but cloned during the build step. This is done by CMake with `ExternalProject`, see: [CMakeLists.txt](CMakeLists.txt).

The `LuaJIT` source code is not provided in this repository, but cloned during the configure step. This is done by CMake via Git, see: [CMakeLists.txt](CMakeLists.txt).

Configure, build and test via CMake (v3.6+), like so:

```cmake
mkdir _build
cd _build
cmake ..
cmake --build .
ctest -V
```

This builds the executables `lua-lab` and `lua-lab_jit`. The Output of both, if everythings works:

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

## LuaJIT (v2.1.0-beta3) License

    LuaJIT -- a Just-In-Time Compiler for Lua. https://luajit.org/

    Copyright (C) 2005-2021 Mike Pall. All rights reserved.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

    [ MIT license: https://www.opensource.org/licenses/mit-license.php ]

    ===============================================================================
    [ LuaJIT includes code from Lua 5.1/5.2, which has this license statement: ]

    Copyright (C) 1994-2012 Lua.org, PUC-Rio.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

    ===============================================================================
    [ LuaJIT includes code from dlmalloc, which has this license statement: ]

    This is a version (aka dlmalloc) of malloc/free/realloc written by
    Doug Lea and released to the public domain, as explained at
    https://creativecommons.org/licenses/publicdomain
