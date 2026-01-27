# 能兼容的最小 cmake 版本
cmake_minimum_required(VERSION 3.10)
# 定义项目名称
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})
# c++ 标准
set(CMAKE_CXX_STANDARD 17)


# raylib路径
set(path_raylib ${PROJECT_SOURCE_DIR}/external/open/raylib)
# nlohmann_json路径
set(path_nlohmann ${PROJECT_SOURCE_DIR}/external/open/nlohmann)


# 头文件路径
set(include_external ${path_raylib}/include ${path_nlohmann})
set(include_project
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/core
    ${PROJECT_SOURCE_DIR}/include/common/base
    ${PROJECT_SOURCE_DIR}/include/common/tool
    ${PROJECT_SOURCE_DIR}/include/gameState
    ${PROJECT_SOURCE_DIR}/include/render/renderer
    ${PROJECT_SOURCE_DIR}/include/render/proxy
    ${PROJECT_SOURCE_DIR}/include/render/texture
    ${PROJECT_SOURCE_DIR}/include/render/font
    ${PROJECT_SOURCE_DIR}/include/handle/event
    ${PROJECT_SOURCE_DIR}/include/handle/handle
    ${PROJECT_SOURCE_DIR}/include/handle/keyboard
    ${PROJECT_SOURCE_DIR}/include/handle/mouse
    ${PROJECT_SOURCE_DIR}/include/save/archive
    ${PROJECT_SOURCE_DIR}/include/save/config
    ${PROJECT_SOURCE_DIR}/include/UI/button

    ${PROJECT_SOURCE_DIR}/include/game
)
# 将头文件全部加入
include_directories(
    ${include_project}
    ${include_external}
)


# 查找当前目录下的所有原文件
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
# 设置可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# 添加源文件到项目
add_executable(${PROJECT_NAME} ${SOURCES} ./MyTest.cpp)


# 指定库路径
target_link_directories(${PROJECT_NAME} PRIVATE ${path_raylib}/lib)
# 链接静态库
target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    raylib
    winmm
)

# # 链接动态库
# target_link_libraries(
#     ${PROJECT_NAME} PRIVATE
#     raylibdll
#     winmm
# )
# # 复制动态库到bin
# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     ${path_raylib}/bin/raylib.dll
#     $<TARGET_FILE_DIR:${PROJECT_NAME}>
# )