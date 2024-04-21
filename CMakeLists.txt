cmake_minimum_required(VERSION 3.25)
project(Example CXX C)

set(CUSTOM_MIOSIX_SETTINGS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(miosix-kernel EXCLUDE_FROM_ALL)
include(miosix-kernel/miosix/cmake/miosix_link_target.cmake)
include(miosix-kernel/miosix/cmake/miosix_add_board_libraries.cmake)

set(CUSTOM_MXGUI_SETTINGS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(mxgui EXCLUDE_FROM_ALL)
include(mxgui/cmake/mxgui_add_board_library.cmake)

set(KPATH ${CMAKE_CURRENT_LIST_DIR}/miosix-kernel/miosix)
miosix_add_board_libraries(stm32f429zi_nokia/config/board_options.cmake)

add_executable(example src/main.cpp)
target_link_libraries(example PUBLIC MxGui::mxgui-stm32f429zi_discovery)
miosix_link_target(example stm32f429zi_nokia)
