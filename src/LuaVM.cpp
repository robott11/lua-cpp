#include "LuaVM.hpp"

#include <lua.hpp>
#include <lualib.h>

LuaVM::LuaVM()
{
    state = luaL_newstate();
    luaL_openlibs(state);
}

void LuaVM::registerFunction(std::string func_name, LuaFunction func_impl)
{
    lua_pushcfunction(state, func_impl);
    lua_setglobal(state, func_name.c_str());
}

void LuaVM::loadScript(std::string file_path)
{
    luaL_loadfile(state, file_path.c_str());
    lua_pcall(state, 0, 0, 0);
}
