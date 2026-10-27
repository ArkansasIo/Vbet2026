#pragma once
#include "vnet/devices/VirtualNIC.hpp"
#include <vector>

namespace vnet::devices
{

    class VirtualHost
    {
    public:
        explicit VirtualHost(std::uint64_t id = 0);
        void addNIC(VirtualNIC nic);
        std::size_t nicCount() const noexcept { return nics_.size(); }
        const std::vector<VirtualNIC> &nics() const noexcept { return nics_; }

    private:
        std::uint64_t id_;
        std::vector<VirtualNIC> nics_;
    };

} // namespace vnet::devices
