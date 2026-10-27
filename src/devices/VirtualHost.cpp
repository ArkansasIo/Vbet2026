#include "vnet/devices/VirtualHost.hpp"

namespace vnet::devices
{

    VirtualHost::VirtualHost(std::uint64_t id) : id_(id) {}

    void VirtualHost::addNIC(VirtualNIC nic)
    {
        nics_.push_back(std::move(nic));
    }

} // namespace vnet::devices
