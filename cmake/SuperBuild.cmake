include(ExternalProject)

find_package(Split QUIET)
if(NOT Split_FOUND)
    ExternalProject_Add(
        SplitProject
        GIT_REPOSITORY https://github.com/gmbeard/split.git
        GIT_SHALLOW ON
        BUILD_ALWAYS ON
        INSTALL_DIR ${CMAKE_INSTALL_PREFIX}
        CMAKE_ARGS
            -DCMAKE_PREFIX_PATH=<INSTALL_DIR>
            -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    )
else()
    add_custom_target(SplitProject)
endif()

ExternalProject_Add(
    IpProject
    DEPENDS SplitProject
    SOURCE_DIR ${PROJECT_SOURCE_DIR}
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DSKIP_SUPERBUILD=ON
        -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
)

set(SKIP_SUPERBUILD ON)
