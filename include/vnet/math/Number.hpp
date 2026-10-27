#pragma once
#include "vnet/arch/UInt1024.hpp"
#include <cstdint>
#include <string>

namespace vnet::math
{

    class Number
    {
    public:
        static std::string toHex(const arch::UInt1024 &value);
        static std::string toDecimal(const arch::UInt1024 &value);
        static arch::UInt1024 add(const arch::UInt1024 &a, const arch::UInt1024 &b);
        static arch::UInt1024 subtract(const arch::UInt1024 &a, const arch::UInt1024 &b);
        static bool isZero(const arch::UInt1024 &value) noexcept;
    };

} // namespace vnet::math
