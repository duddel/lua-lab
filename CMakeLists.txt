cmake_minimum_required(VERSION 3.6)
find_package(Git)

project(lua-lab)

enable_testing()
include(ExternalProject)

ExternalProject_Add(lua-clone
  GIT_REPOSITORY https://github.com/lua/lua.git
  GIT_TAG v5.3.5
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
  GIT_SHALLOW ON
)

ExternalProject_Get_property(lua-clone SOURCE_DIR)

# all sources, except lua.c (which contains a stand-alone
# interpeter and a main(), which is useless when embedding
# Lua, like we do here)
list(APPEND LUA_SOURCES
  ${SOURCE_DIR}/lapi.c
  ${SOURCE_DIR}/lauxlib.c
  ${SOURCE_DIR}/lbaselib.c
  ${SOURCE_DIR}/lbitlib.c
  ${SOURCE_DIR}/lcode.c
  ${SOURCE_DIR}/lcorolib.c
  ${SOURCE_DIR}/lctype.c
  ${SOURCE_DIR}/ldblib.c
  ${SOURCE_DIR}/ldebug.c
  ${SOURCE_DIR}/ldo.c
  ${SOURCE_DIR}/ldump.c
  ${SOURCE_DIR}/lfunc.c
  ${SOURCE_DIR}/lgc.c
  ${SOURCE_DIR}/linit.c
  ${SOURCE_DIR}/liolib.c
  ${SOURCE_DIR}/llex.c
  ${SOURCE_DIR}/lmathlib.c
  ${SOURCE_DIR}/lmem.c
  ${SOURCE_DIR}/loadlib.c
  ${SOURCE_DIR}/lobject.c
  ${SOURCE_DIR}/lopcodes.c
  ${SOURCE_DIR}/loslib.c
  ${SOURCE_DIR}/lparser.c
  ${SOURCE_DIR}/lstate.c
  ${SOURCE_DIR}/lstring.c
  ${SOURCE_DIR}/lstrlib.c
  ${SOURCE_DIR}/ltable.c
  ${SOURCE_DIR}/ltablib.c
  ${SOURCE_DIR}/ltests.c
  ${SOURCE_DIR}/ltm.c
  ${SOURCE_DIR}/lundump.c
  ${SOURCE_DIR}/lutf8lib.c
  ${SOURCE_DIR}/lvm.c
  ${SOURCE_DIR}/lzio.c
)

set_property(SOURCE ${LUA_SOURCES} PROPERTY GENERATED TRUE)


# get a specific commit of LuaJIT
set(LUA_JIT_COMMIT_SHA abf43867b48c55e87d932817bf8155939b44b7c2)

# clone LuaJIT
execute_process(COMMAND "${GIT_EXECUTABLE}" clone https://github.com/WohlSoft/LuaJIT.git
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
# reset LuaJIT clone to the requested commit
execute_process(COMMAND "${GIT_EXECUTABLE}" checkout "${LUA_JIT_COMMIT_SHA}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/LuaJIT"
)


# get a specific commit of LuaBridge
set(LUA_BRIDGE_COMMIT_SHA fab7b33b896a42dcc865ba5ecdbacd9f409137f8)

# clone LuaBridge
execute_process(COMMAND "${GIT_EXECUTABLE}" clone https://github.com/vinniefalco/LuaBridge.git
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
# reset LuaBridge clone to the requested commit
execute_process(COMMAND "${GIT_EXECUTABLE}" checkout "${LUA_BRIDGE_COMMIT_SHA}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/LuaBridge"
)



# 1st executable: original Lua
add_executable(${CMAKE_PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${LUA_SOURCES}
)

add_dependencies(${CMAKE_PROJECT_NAME} lua-clone)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  ${SOURCE_DIR}
)


# 2nd executable: LuaJIT
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/LuaJIT)

add_executable(${CMAKE_PROJECT_NAME}_jit
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}_jit PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/LuaJIT/src
)

target_link_libraries(${CMAKE_PROJECT_NAME}_jit PUBLIC
  libluajit
)


# 3rd executable: original Lua + LuaBridge
add_executable(${CMAKE_PROJECT_NAME}_bridge
  ${CMAKE_CURRENT_SOURCE_DIR}/main_bridge.cpp
  ${LUA_SOURCES}
)

add_dependencies(${CMAKE_PROJECT_NAME}_bridge lua-clone)

target_include_directories(${CMAKE_PROJECT_NAME}_bridge PRIVATE
  ${SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/LuaBridge/Source
)


# add the executables as a tests to be run by ctest
add_test(
  NAME ${CMAKE_PROJECT_NAME}_run
  COMMAND ${CMAKE_PROJECT_NAME}
)

add_test(
  NAME ${CMAKE_PROJECT_NAME}_jit_run
  COMMAND ${CMAKE_PROJECT_NAME}_jit
)

add_test(
  NAME ${CMAKE_PROJECT_NAME}_bridge_run
  COMMAND ${CMAKE_PROJECT_NAME}_bridge
)
