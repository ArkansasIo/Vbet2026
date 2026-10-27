#include "vnet/devices/VirtualNIC.hpp"

namespace vnet::devices
{

    VirtualNIC::VirtualNIC(std::uint64_t id) : id_(id) {}

    std::string VirtualNIC::name() const
    {
        return "eth" + std::to_string(id_);
    }

} // namespace vnet::devices
