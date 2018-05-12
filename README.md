## IP
Utilities for handling IP addresses.

*License: MIT (See `LICENSE.txt`)*

### Example

```c++
#include "ip/ipv4.hpp"

auto main(int, char const**) -> int {
    // Convert from a string...
    auto ip = ip::IPv4::from_string("127.0.0.1");

    // Explicitly convertible to a uint32_t (host byte order)...
    auto ip_val = static_cast<uint32_t>(ip);

    return 0;
}
```
