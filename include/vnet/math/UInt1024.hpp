#pragma once
#include <array>
#include <cstdint>
#include <string>

namespace vnet::math {
struct UInt1024 {
    std::array<std::uint64_t, 16> words{};
    static constexpr std::size_t bit_width = 1024;
    static constexpr std::size_t byte_width = 128;
    static constexpr std::size_t word_count = 16;
    std::string toHex() const;
    bool operator==(const UInt1024&) const = default;
};
static_assert(sizeof(UInt1024) == 128);
}
