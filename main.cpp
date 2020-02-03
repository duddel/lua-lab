extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int main()
{
  const char luaCode[] =
      "function f(x,y,a) \n\
      z = a*math.cos(math.sqrt(x*x+y*y)) \n\
      if z > 0 then \n\
        return z \n\
      else \n\
        return 0 \n\
      end \n\
    end";

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dostring(L, luaCode);

  for (float i = -1.5707963f; i <= 1.5707963f; i += 0.3141592f)
  {
    for (float j = -1.5707963f; j <= 1.5707963f; j += 0.3141592f)
    {
      lua_getglobal(L, "f");
      lua_pushnumber(L, i);
      lua_pushnumber(L, j);
      lua_pushnumber(L, 4.0f);
      lua_call(L, 3, 1);
      float z = lua_tonumber(L, 1);
      printf("%.1f ", z);
      lua_pop(L, 1);
    }
    printf("\n");
  }

  lua_close(L);

  return 0;
}
