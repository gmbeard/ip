cmake_minimum_required(VERSION 3.7)

project(Ip)
set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/submodules/cmake
)

list(APPEND 
    CMAKE_PREFIX_PATH
    ${CMAKE_CURRENT_LIST_DIR}/deps
)

include(InstallExternals)

#add_subdirectory(submodules/split)
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
