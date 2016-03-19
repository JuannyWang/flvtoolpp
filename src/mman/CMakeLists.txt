set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c14")

include_directories("${FLVTOOLPP_SOURCE_DIR}/include")

add_library (mman src/mman.c)

target_include_directories (mman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

function(add_clang_static_analysis target)
    get_target_property(SRCs ${target} SOURCES)
    add_library(${target}_analyze OBJECT EXCLUDE_FROM_ALL ${SRCs})
    set_target_properties(${target}_analyze PROPERTIES
            COMPILE_OPTIONS "--analyze"
            EXCLUDE_FROM_DEFAULT_BUILD true)
endfunction()