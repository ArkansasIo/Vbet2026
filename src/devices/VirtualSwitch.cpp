#include "vnet/devices/VirtualSwitch.hpp"

namespace vnet::devices
{

    VirtualSwitch::VirtualSwitch(std::uint64_t id, std::size_t portCount)
        : id_(id), portCount_(portCount) {}

    void VirtualSwitch::forward(const packet::Packet &packet)
    {
        if (packet.payload.empty())
            return;
        ++frames_;
    }

} // namespace vnet::devices
