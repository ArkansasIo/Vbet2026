#include "vnet/math/Number.hpp"
#include <algorithm>
#include <format>

#if defined(_MSC_VER)
#include <intrin.h>
#endif

namespace vnet::math
{

    namespace
    {
        // Divide a 128-bit value (hi:lo) by a 64-bit divisor, portable across MSVC and GCC/Clang.
        struct Div128Result
        {
            std::uint64_t quotient;
            std::uint64_t remainder;
        };

        Div128Result div128By64(std::uint64_t hi, std::uint64_t lo, std::uint64_t divisor)
        {
#if defined(_MSC_VER)
            std::uint64_t quotient = 0, remainder = 0;
            remainder = _udiv128(hi, lo, divisor, &quotient);
            return {quotient, remainder};
#else
            const unsigned __int128 cur = (static_cast<unsigned __int128>(hi) << 64) | lo;
            return {static_cast<std::uint64_t>(cur / divisor), static_cast<std::uint64_t>(cur % divisor)};
#endif
        }

        // Add two 64-bit words with carry, return sum and carry.
        std::uint64_t addWithCarry(std::uint64_t a, std::uint64_t b, std::uint64_t &carry)
        {
            const std::uint64_t sum = a + b;
            const std::uint64_t sumCarry = (sum < a) ? 1u : 0u;
            const std::uint64_t out = sum + carry;
            const std::uint64_t outCarry = (out < sum) ? 1u : 0u;
            carry = sumCarry + outCarry;
            return out;
        }
    }

    std::string Number::toHex(const arch::UInt1024 &value)
    {
        std::string out = "0x";
        for (std::size_t i = value.words.size(); i-- > 0;)
            out += std::format("{:016X}", value.words[i]);
        return out;
    }

    std::string Number::toDecimal(const arch::UInt1024 &value)
    {
        arch::UInt1024 n = value;
        std::string digits;
        const std::uint64_t base = 1'000'000'000'000'000'000ull; // 10^18 per step
        while (!isZero(n))
        {
            std::uint64_t rem = 0;
            for (std::size_t i = n.words.size(); i-- > 0;)
            {
                const auto result = div128By64(rem, n.words[i], base);
                n.words[i] = result.quotient;
                rem = result.remainder;
            }
            std::string chunk = std::format("{:018}", rem);
            if (digits.empty())
            {
                std::size_t first = chunk.find_first_not_of('0');
                digits = first == std::string::npos ? "0" : chunk.substr(first);
            }
            else
            {
                digits = chunk + digits;
            }
        }
        return digits.empty() ? "0" : digits;
    }

    arch::UInt1024 Number::add(const arch::UInt1024 &a, const arch::UInt1024 &b)
    {
        arch::UInt1024 out;
        std::uint64_t carry = 0;
        for (std::size_t i = 0; i < out.words.size(); ++i)
        {
            out.words[i] = addWithCarry(a.words[i], b.words[i], carry);
        }
        return out;
    }

    arch::UInt1024 Number::subtract(const arch::UInt1024 &a, const arch::UInt1024 &b)
    {
        arch::UInt1024 out;
        std::uint64_t borrow = 0;
        for (std::size_t i = 0; i < out.words.size(); ++i)
        {
            const std::uint64_t bi = b.words[i] + borrow;
            borrow = a.words[i] < bi ? 1 : 0;
            out.words[i] = a.words[i] - bi;
        }
        return out;
    }

    bool Number::isZero(const arch::UInt1024 &value) noexcept
    {
        return std::all_of(value.words.begin(), value.words.end(), [](std::uint64_t w)
                           { return w == 0; });
    }

} // namespace vnet::math
