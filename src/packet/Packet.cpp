#include "vnet/packet/Packet.hpp"
#include <format>

namespace vnet::packet
{

    std::string Packet::summary() const
    {
        return std::format("id={} etherType=0x{:04X} bytes={}", id, etherType, payload.size());
    }

} // namespace vnet::packet
