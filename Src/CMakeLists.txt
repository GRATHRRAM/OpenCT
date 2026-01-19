file(GLOB_RECURSE SOURCE  "${CMAKE_SOURCE_DIR}/Src/*.cpp")

add_executable(OpenCT ${SOURCE})

target_link_libraries(OpenCT PRIVATE raylib m)
