add_library(
    headers
    INTERFACE
)

target_include_directories(
    headers
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_compile_features(
    headers
    INTERFACE
        cxx_decltype_auto
)

install(
    DIRECTORY
        ip
    DESTINATION
        include
)

install(
    TARGETS
        headers
    EXPORT
        IpIncludesExport
)

add_library(Ip::headers ALIAS headers)
