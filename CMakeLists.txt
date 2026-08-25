cmake_minimum_required(VERSION 3.24)

project(
    mini_stl
    VERSION 0.1.0
    DESCRIPTION "STL-inspired containers, smart pointers, and allocators"
    LANGUAGES CXX
)

option(MINISTL_BUILD_TESTS "Build Mini STL tests" ON)
option(MINISTL_BUILD_EXAMPLES "Build Mini STL examples" ON)
option(MINISTL_ENABLE_SANITIZERS "Enable supported sanitizers" OFF)
option(MINISTL_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" ON)

add_library(ministl INTERFACE)
add_library(ministl::ministl ALIAS ministl)

target_compile_features(ministl INTERFACE cxx_std_20)

target_sources(
    ministl
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/ministl/memory/lifetime.hpp
            include/ministl/memory/raw_buffer.hpp
)

target_include_directories(
    ministl
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

if(MSVC)
    target_compile_options(
        ministl
        INTERFACE
            /W4
            /permissive-
            /EHsc
    )

    if(MINISTL_WARNINGS_AS_ERRORS)
        target_compile_options(ministl INTERFACE /WX)
    endif()
else()
    target_compile_options(
        ministl
        INTERFACE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
    )

    if(MINISTL_WARNINGS_AS_ERRORS)
        target_compile_options(ministl INTERFACE -Werror)
    endif()
endif()

if(MINISTL_ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(
        ministl
        INTERFACE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
    )

    target_link_options(
        ministl
        INTERFACE
            -fsanitize=address,undefined
    )
endif()

if(MINISTL_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

if(MINISTL_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()