cmake_minimum_required(VERSION 3.25)
project(Example CXX C)

set(CUSTOM_MIOSIX_SETTINGS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(miosix-kernel EXCLUDE_FROM_ALL)
include(miosix-kernel/miosix/cmake/miosix_link_target.cmake)

add_executable(example src/main.cpp)
miosix_link_target(example stm32f429zi_stm32f4discovery)
