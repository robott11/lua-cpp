#include <cstring>
#include <iostream>
#include <lua.hpp>

int main(int argc, char** argv)
{
    void* ud = nullptr;
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    const char* msg = "Hello World!";

    int value_type = lua_getglobal(L, "print");
    lua_pushlstring(L, msg, strlen(msg));
    lua_call(L, 1, 1);

    return EXIT_SUCCESS;
}