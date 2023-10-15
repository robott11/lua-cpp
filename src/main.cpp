#include <cstring>
#include <iostream>
#include <lua.hpp>
#include <string>

static int l_example_function(lua_State* L)
{
    const char* message = lua_tostring(L, 1);

    std::string final_message = "MESSAGE FROM CPP FUNC: ";
    final_message.append(message);

    lua_pushstring(L, final_message.c_str());

    return 1;
}

int main(int argc, char** argv)
{
    void* ud = nullptr;
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushcfunction(L, l_example_function);
    lua_setglobal(L, "example_function");

    const char* config_file = "../example_script.lua";

    luaL_loadfile(L, config_file);
    lua_pcall(L, 0, 0, 0);

    return EXIT_SUCCESS;
}