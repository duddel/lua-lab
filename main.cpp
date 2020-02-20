/*
Copyright (c) 2020 Alexander Scholz

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
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int main()
{
    // the Lua code can come from anywhere (from file, command line, etc.)
    const char luaCode[] =
        "function f(x,y,a) \n\
        z = a*math.cos(math.sqrt(x*x+y*y)) \n\
        if z > 0 then \n\
          return z \n\
        else \n\
          return 0 \n\
        end \n\
      end";

    // create a Lua state and open standard libraries
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // execute the Lua code from above
    luaL_dostring(L, luaCode);

    for (float i = -1.5707963f; i <= 1.5707963f; i += 0.3141592f)
    {
        for (float j = -1.5707963f; j <= 1.5707963f; j += 0.3141592f)
        {
            // push the Lua function f() onto the Lua stack
            lua_getglobal(L, "f");

            // push the three arguments for f() onto the Lua stack
            lua_pushnumber(L, i);
            lua_pushnumber(L, j);
            lua_pushnumber(L, 4.0f);

            // call f() and tell Lua that 3 arguments are provided and 1 return value is expected
            lua_call(L, 3, 1);
            // now, f() and the arguments are popped from the Lua stack, the return value is pushed

            // get the return value of f() from the Lua stack and print it
            float z = lua_tonumber(L, 1);
            printf("%.1f ", z);

            // pop the return value from the Lua stack
            lua_pop(L, 1);
        }
        printf("\n");
    }

    // close the Lua state
    lua_close(L);

    return 0;
}
