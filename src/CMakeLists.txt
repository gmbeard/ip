find_package(Split REQUIRED)

add_library(
    ip
    STATIC
        ipv4.cpp
)

target_link_libraries(
    ip
    PUBLIC
        Ip::headers
    PRIVATE
        Split::SplitLibrary
)

target_compile_options(
    ip
    PUBLIC
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Werror -Wextra>
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

target_compile_definitions(
    ip
    PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:_SCL_SECURE_NO_WARNINGS>
)

install(
    TARGETS
        ip
    EXPORT
        IpLibraryExport
    ARCHIVE DESTINATION lib
)

add_library(Ip::ip ALIAS ip)
