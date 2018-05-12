cmake_minimum_required(VERSION 3.7)

project(Ip)

add_subdirectory(submodules/split)
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
