cmake_minimum_required(VERSION 3.15)
project(hello-cpp)
set(CMAKE_PREFIX_PATH D:/ggWorkspace/mingw-vcpkg/vcpkg/installed/x64-mingw-dynamic/share/fmt)
find_package(fmt REQUIRED)
#find_package(catch2 CONFIG REQUIRED)
add_library(hellolib src/hello.cpp)
add_executable(main src/main.cpp)

target_compile_features(hellolib PUBLIC cxx_std_17)
target_compile_features(main PUBLIC cxx_std_17)
target_include_directories(hellolib
    PUBLIC  $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(hellolib PRIVATE fmt::fmt)
target_link_libraries(main PRIVATE hellolib fmt::fmt)