#include "ip/ipv4.hpp"
#include "split/split.hpp"
#include <algorithm>

using namespace ip;
using std::begin;
using std::end;

auto slice_to_octet(split::Slice const& s) -> uint8_t {

    if (!s.size()) {
        throw InvalidIPv4Error { "Empty octet string" };
    }

    if (s.size() > 3) {
        throw InvalidIPv4Error { "Too many octet digits" };
    }

    uint16_t octet = 0;
    std::for_each(s.start, s.end, [&](auto c) {
        auto n = c - '0';
        if (n < 0 || n > 9) {
            throw InvalidIPv4Error { "Invalid octet character" };
        }

        octet = octet * 10 + static_cast<uint8_t>(n);
    });

    if (octet > 255) {
        throw InvalidIPv4Error { "Octet outside valid range" };
    }

    return static_cast<uint8_t>(octet);
}

/*constexpr*/ IPv4::IPv4() noexcept :
    IPv4{ {0, 0, 0, 0} }
{ }

/*constexpr*/ IPv4::IPv4(uint8_t const (&c)[4]) noexcept :
    components_{ { c[0], c[1], c[2], c[3] } }
{ }

/*constexpr*/ IPv4::operator uint32_t() const noexcept {
    return
        static_cast<uint32_t>(components_[0] << 24) |
        static_cast<uint32_t>(components_[1] << 16) |
        static_cast<uint32_t>(components_[2] << 8)  |
        static_cast<uint32_t>(components_[3]);
}

auto IPv4::from_string(std::string const& s) -> IPv4 {

    auto parts = split::split(s, ".");
    if (parts.size() != 4) {
        throw InvalidIPv4Error { "Invalid IPv4 format" };
    }

    uint8_t components[4] = {0, 0, 0, 0};

    std::transform(begin(parts), 
                   end(parts), 
                   begin(components),
                   slice_to_octet);
                
    return { components };
}

/*constexpr*/ auto ip::localhost() -> IPv4 {
    return { { 127, 0, 0, 1 } };
}
