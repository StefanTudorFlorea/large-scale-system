# config
set(CMAKE_TOOLCHAIN_FILE "./tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
cmake_minimum_required(VERSION 3.20)
project(large-scale-system)

# output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 3rd party
find_package(Crow     CONFIG REQUIRED)
find_package(fmt      CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(httplib  CONFIG REQUIRED)

# services
add_subdirectory("src/serviceOne")
add_subdirectory("src/serviceTwo")
add_subdirectory("src/serviceThree")
add_subdirectory("src/web")