cmake_minimum_required (VERSION 2.8.11)
project (minunit)

SET(MAX_TESTS 128 CACHE STRING "Maximum tests per suit")
SET(32bit CACHE BOOL "32 Bit target")

configure_file(config.h.in config.h)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR})
add_library (minunit STATIC src/minunit.c)
if(32bit)
    set_target_properties(minunit PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
else(32bit)
    set_target_properties(minunit PROPERTIES COMPILE_FLAGS "-m64" LINK_FLAGS "-m64")
endif(32bit)

target_include_directories(minunit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install (TARGETS minunit DESTINATION lib)
install (FILES include/minunit.h DESTINATION include)