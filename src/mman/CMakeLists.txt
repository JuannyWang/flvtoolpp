set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

include_directories("${FLVTOOLPP_SOURCE_DIR}/include/mman/include")

file(GLOB MMAN_SRC "src/*.c")

add_library (mman ${MMAN_SRC})

target_include_directories (mman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})