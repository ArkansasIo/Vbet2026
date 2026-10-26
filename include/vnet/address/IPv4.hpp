#pragma once
#include <array>
#include <cstdint>
#include <string>
#include <string_view>

namespace vnet::address {

struct IPv4Octet {
    std::uint8_t value{0};
    bool valid() const noexcept { return true; }
    std::string decimal9() const;
};

class IPv4 {
public:
    IPv4() = default;
    IPv4(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d);
    static IPv4 parse(std::string_view text);
    std::string toString() const;
    std::uint32_t packed() const noexcept;
    const IPv4Octet& operator[](std::size_t i) const { return octets_.at(i); }
private:
    std::array<IPv4Octet, 4> octets_{};
};

} // namespace vnet::address
