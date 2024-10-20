cmake_minimum_required(VERSION 3.16)
project(Example C CXX)

# This allows to use custom miosix_settings.h and mxgui_settings.h files
set(MIOSIX_SETTINGS_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Include directory for miosix_settings.h")
set(MXGUI_SETTINGS_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Include directory for miosix_settings.h")

# Board selection
set(MIOSIX_OPT_BOARD stm32f429zi_stm32f4discovery CACHE STRING "Target board")

# Include dependencies
add_compile_definitions($<$<COMPILE_LANGUAGE:C,CXX>:PARSING_FROM_IDE>)
add_subdirectory(miosix-kernel EXCLUDE_FROM_ALL)
include(LinkTarget)
add_subdirectory(mxgui EXCLUDE_FROM_ALL)

# set(KPATH ${CMAKE_CURRENT_LIST_DIR}/miosix-kernel/miosix)
# miosix_add_board_libraries(stm32f429zi_nokia/config/board_options.cmake)

add_executable(example src/main.cpp)
target_link_libraries(example PUBLIC mxgui)
miosix_link_target(example)

