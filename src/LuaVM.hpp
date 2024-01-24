#pragma once

#include <lua.hpp>
#include <string>

#define DECLARE_LUA_FUNCTION(name, lua_state) \
    int name(Lua_State* lua_state)

typedef int(*LuaFunction)(lua_State*);

class LuaVM {
public:
    LuaVM();

    lua_State* getState() { return m_state; }

    void registerFunction(std::string func_name, LuaFunction func_impl);
    void loadScript(std::string file_path);

private:
    lua_State* m_state;
};
