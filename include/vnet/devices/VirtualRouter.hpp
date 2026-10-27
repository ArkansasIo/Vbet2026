#pragma once
#include "vnet/routing/RoutingTable.hpp"
#include <cstdint>

namespace vnet::devices
{

    class VirtualRouter
    {
    public:
        explicit VirtualRouter(std::uint64_t id = 0);
        const routing::RoutingTable &routingTable() const noexcept { return table_; }
        routing::RoutingTable &routingTable() noexcept { return table_; }
        std::uint32_t resolveNextHop(std::uint32_t address) const;

    private:
        std::uint64_t id_;
        routing::RoutingTable table_;
    };

} // namespace vnet::devices
