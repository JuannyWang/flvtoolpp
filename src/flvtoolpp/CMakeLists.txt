set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
        "${FLVTOOLPP_SOURCE_DIR}/include/flvtoolpp/include"
        "${FLVTOOLPP_SOURCE_DIR}/3rdparty/include"
        "${FLVTOOLPP_SOURCE_DIR}/3rdparty/boost.shared_ptr"
)

file(GLOB FLVTOOLPP_SRC "src/*.cpp")

add_executable(flvtoolpp ${FLVTOOLPP_SRC})

if (WIN32)
    include_directories("${FLVTOOLPP_SOURCE_DIR}/include/mman/include")

    target_link_libraries(flvtoolpp LINK_PUBLIC mman wsock32 ws2_32)
endif ()