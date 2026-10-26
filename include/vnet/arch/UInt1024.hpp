#pragma once
#include <array>
#include <cstdint>
#include <string>

namespace vnet::arch {

struct UInt1024 {
    std::array<std::uint64_t, 16> words{};
    static constexpr std::size_t BitWidth = 1024;
    static constexpr std::size_t ByteWidth = 128;
    static constexpr std::size_t WordCount = 16;

    void clear() noexcept { words.fill(0); }
    std::uint64_t& word(std::size_t index) { return words.at(index); }
    const std::uint64_t& word(std::size_t index) const { return words.at(index); }
};

static_assert(sizeof(UInt1024) == 128);

} // namespace vnet::arch
