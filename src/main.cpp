#include "LuaVM.hpp"

DECLARE_LUA_FUNCTION(lua_print_from_cpp, lua_state) {
    const char* message = luaL_checkstring(lua_state, 1);

    std::string final_message = "MESSAGE FROM CPP FUNC: ";
    final_message.append(message);

    lua_pushstring(lua_state, final_message.c_str());

    return 1;
}

int main(int argc, char** argv)
{
    // lua_State* L = luaL_newstate();
    // luaL_openlibs(L);
    //
    // lua_pushcfunction(L, l_example_function);
    // lua_setglobal(L, "example_function");
    //
    // const char* config_file = "../example_script.lua";
    //
    // luaL_loadfile(L, config_file);
    // lua_pcall(L, 0, 0, 0);
    //
    // return EXIT_SUCCESS;
    
    auto lua = new LuaVM;
    lua->registerFunction("print_from_cpp", lua_print_from_cpp(lua.getState()));
    lua->loadScript("../example_script.lua");

    return 0;
}
