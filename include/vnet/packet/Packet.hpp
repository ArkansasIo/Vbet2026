#pragma once
#include <cstdint>
#include <vector>
#include <string>

namespace vnet::packet {
struct Packet {
    std::uint64_t id{};
    std::uint16_t etherType{};
    std::vector<std::uint8_t> payload;
    std::string summary() const;
};
}
