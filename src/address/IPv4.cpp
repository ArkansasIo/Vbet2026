#include "vnet/address/IPv4.hpp"
#include <format>
#include <sstream>
#include <stdexcept>

namespace vnet::address {

std::string IPv4Octet::decimal9() const { return std::format("{:09}", value); }

IPv4::IPv4(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d)
    : octets_{{{a}, {b}, {c}, {d}}} {}

IPv4 IPv4::parse(std::string_view text) {
    std::stringstream ss(std::string{text});
    int a, b, c, d; char dot1, dot2, dot3;
    if (!(ss >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d) || dot1 != '.' || dot2 != '.' || dot3 != '.')
        throw std::invalid_argument("Invalid IPv4 address");
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255)
        throw std::out_of_range("IPv4 octet outside 0..255");
    return IPv4(static_cast<std::uint8_t>(a), static_cast<std::uint8_t>(b), static_cast<std::uint8_t>(c), static_cast<std::uint8_t>(d));
}

std::string IPv4::toString() const {
    return std::format("{}.{}.{}.{}", octets_[0].value, octets_[1].value, octets_[2].value, octets_[3].value);
}

std::uint32_t IPv4::packed() const noexcept {
    return (static_cast<std::uint32_t>(octets_[0].value) << 24) |
           (static_cast<std::uint32_t>(octets_[1].value) << 16) |
           (static_cast<std::uint32_t>(octets_[2].value) << 8) |
           octets_[3].value;
}

} // namespace vnet::address
