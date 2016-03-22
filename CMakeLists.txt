cmake_minimum_required(VERSION 3.3)
project(FLVTOOLPP)

set(FLVTOOLPP_VERSION_MAJOR 1)
set(FLVTOOLPP_VERSION_MINOR 2)
set(FLVTOOLPP_VERSION_PATCH 2)

if (WIN32)
    add_subdirectory(src/mman)
endif ()

add_subdirectory(src/flvtoolpp)

function(add_clang_static_analysis target)
    get_target_property(SRCs ${target} SOURCES)
    add_library(${target}_analyze OBJECT EXCLUDE_FROM_ALL ${SRCs})
    set_target_properties(${target}_analyze PROPERTIES
            COMPILE_OPTIONS "--analyze"
            EXCLUDE_FROM_DEFAULT_BUILD true)
endfunction()