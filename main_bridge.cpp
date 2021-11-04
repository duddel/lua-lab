/*
Copyright (c) 2020-2021 Alexander Scholz

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#include <cstdio>
#include <array>
#include <vector>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "LuaBridge/LuaBridge.h"
#include "LuaBridge/Array.h"
#include "LuaBridge/Vector.h"

int g_value;
int multValue(int factor)
{
    return factor * g_value;
}

class A
{
public:
    std::string _name;
    A(std::string name) { _name = name; }
    void hello()
    {
        std::printf("my name is %s\n", _name.c_str());
    }
};

std::vector<float> g_vec = {7.0f, 14.0f, 21.0f, 28.0f};

void printArray(std::array<float, 3> arr)
{
    std::printf("C++ receive Lua table as std::array: ");
    for (const auto &f : arr)
    {
        std::printf("%f ", f);
    }
    std::printf("\n");
}

void printVector(std::vector<float> vec)
{
    std::printf("C++ receive Lua table as std::vector: ");
    for (const auto &f : vec)
    {
        std::printf("%f ", f);
    }
    std::printf("\n");
}

int main()
{
    // Lua code that is run below
    const std::string luaCode = R"(
        print("Lua -> set global int (C++), call function, print result:")
        lab.value = 14
        result = lab.multValue(3)
        print(tostring(result))

        print("Lua -> construct C++ object, call method:")
        a = lab.A("Luke")
        a:hello()

        print("Lua -> read global std::vector from C++:")
        for k,v in pairs(lab.vec) do
          print("vec[" .. tostring(k) .. "]: " .. tostring(v))
        end

        b = {}
        b[1] = 1.0
        b[2] = 2.0
        b[3] = 3.0
        lab.printArray(b)

        c = {}
        for i = 1,10,1
        do
          c[i] = i*i
        end
        lab.printVector(c)
    )";

    // create a Lua state and open standard libraries
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // register C++ information via LuaBridge
    luabridge::getGlobalNamespace(L)
        .beginNamespace("lab")
        .addProperty("value", &g_value)
        .addFunction("multValue", multValue)
        .beginClass<A>("A")
        .addConstructor<void (*)(std::string)>()
        .addFunction("hello", &A::hello)
        .endClass()
        .addProperty("vec", &g_vec)
        .addFunction("printArray", printArray)
        .addFunction("printVector", printVector)
        .endNamespace();

    // execute the Lua code from above
    luaL_dostring(L, luaCode.c_str());

    // close the Lua state
    lua_close(L);

    return 0;
}
