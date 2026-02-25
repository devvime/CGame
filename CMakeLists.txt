cmake_minimum_required(VERSION 3.16)
project(Engine3D C)

set(CMAKE_C_STANDARD 11)

find_package(raylib 5.0 REQUIRED)

file(GLOB_RECURSE SOURCES 
    engine/*.c
    src/*.c
)

set(CJSON_SOURCES external/cJSON/cJSON.c)

add_executable(engine3d
    ${SOURCES}
    ${CJSON_SOURCES}
)

target_include_directories(engine3d PRIVATE
    external/cJSON
)

target_link_libraries(engine3d
    raylib
)