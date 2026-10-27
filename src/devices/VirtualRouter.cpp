#include "vnet/devices/VirtualRouter.hpp"
#include <optional>

namespace vnet::devices
{

    VirtualRouter::VirtualRouter(std::uint64_t id) : id_(id) {}

    std::uint32_t VirtualRouter::resolveNextHop(std::uint32_t address) const
    {
        const auto route = table_.lookup(address::IPv4(
            static_cast<std::uint8_t>(address >> 24),
            static_cast<std::uint8_t>(address >> 16),
            static_cast<std::uint8_t>(address >> 8),
            static_cast<std::uint8_t>(address)));
        return route ? route->nextHop : 0u;
    }

} // namespace vnet::devices
