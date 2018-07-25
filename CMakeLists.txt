cmake_minimum_required(VERSION 3.7)

project(Ip)
set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
)

option(SKIP_SUPERBUILD
    "Superbuild for ${PROJECT_NAME}"
    OFF
)

if(NOT SKIP_SUPERBUILD)
    include(SuperBuild)
    return()
endif()

add_subdirectory(include)
add_subdirectory(src)

install(
    EXPORT
        IpIncludesExport
    NAMESPACE
        Ip::
    FILE
        IpIncludes.cmake
    DESTINATION
        lib/cmake/ip
)

install(
    EXPORT
        IpLibraryExport
    NAMESPACE
        Ip::
    FILE
        IpLibrary.cmake
    DESTINATION
        lib/cmake/ip
)

install(
    FILES
        cmake/IpConfig.cmake
    DESTINATION
        lib/cmake/ip
)
