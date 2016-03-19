set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
        "${FLVTOOLPP_SOURCE_DIR}/include"
        "${FLVTOOLPP_SOURCE_DIR}/ext/include"
        "${FLVTOOLPP_SOURCE_DIR}/ext/boost.shared_ptr"
)

add_executable(flvtoolpp src/AMFData.cpp src/flvtool++.cpp)

if (WIN32)
    target_link_libraries(flvtoolpp LINK_PUBLIC mman wsock32 ws2_32)
endif ()

function(add_clang_static_analysis target)
    get_target_property(SRCs ${target} SOURCES)
    add_library(${target}_analyze OBJECT EXCLUDE_FROM_ALL ${SRCs})
    set_target_properties(${target}_analyze PROPERTIES
            COMPILE_OPTIONS "--analyze"
            EXCLUDE_FROM_DEFAULT_BUILD true)
endfunction()