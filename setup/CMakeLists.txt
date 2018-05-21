cmake_minimum_required(VERSION 3.7)

include(ExternalProject)

ExternalProject_Add(
    Split
    GIT_REPOSITORY https://github.com/gmbeard/split.git
    INSTALL_DIR ${INSTALL_DEPS_TO}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
