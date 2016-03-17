cmake_minimum_required(VERSION 3.3)
project(FLVTOOLPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
        "${FLVTOOLPP_SOURCE_DIR}/ext/include"
        "${FLVTOOLPP_SOURCE_DIR}/ext/boost.shared_ptr"
)

set(
        SOURCE_FILES
        AMFData.cpp
        mman.c
        flvtool++.cpp
)

add_executable(flvtoolpp ${SOURCE_FILES})

if (WIN32)
    target_link_libraries(flvtoolpp wsock32 ws2_32)
endif()

function(add_clang_static_analysis target)
    get_target_property(SRCs ${target} SOURCES)
    add_library(${target}_analyze OBJECT EXCLUDE_FROM_ALL ${SRCs})
    set_target_properties(${target}_analyze PROPERTIES
            COMPILE_OPTIONS "--analyze"
            EXCLUDE_FROM_DEFAULT_BUILD true)
endfunction()