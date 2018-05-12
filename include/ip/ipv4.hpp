#ifndef IP_IPV4_HPP_INCLUDED
#define IP_IPV4_HPP_INCLUDED

#include <cstdint>
#include <array>
#include <stdexcept>

namespace ip {

    struct InvalidIPv4Error : std::runtime_error {
        InvalidIPv4Error(char const* what) :
            std::runtime_error{what}
        { }
    };

    struct IPv4 {
        /*constexpr*/ IPv4() noexcept;
        /*constexpr*/ IPv4(uint8_t const(&components)[4]) noexcept;
        /*constexpr*/ explicit operator uint32_t() const noexcept;
        static auto from_string(std::string const&) -> IPv4;
    private:
        std::array<uint8_t, 4> components_;
    };

    /*constexpr*/ auto localhost() -> IPv4;
}
#endif //IP_IPV4_HPP_INCLUDED
