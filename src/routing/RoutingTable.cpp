#include "vnet/routing/RoutingTable.hpp"
#include <algorithm>

namespace vnet::routing
{

    void RoutingTable::add(Route route)
    {
        routes_.push_back(std::move(route));
    }

    std::optional<Route> RoutingTable::lookup(address::IPv4 address) const
    {
        const std::uint32_t addr = address.packed();
        const Route *best = nullptr;
        for (const auto &route : routes_)
        {
            const std::uint32_t mask = route.prefix == 0
                                           ? 0u
                                           : (~0u << (32 - route.prefix));
            if ((addr & mask) == (route.network.packed() & mask))
            {
                if (!best || route.prefix > best->prefix)
                    best = &route;
            }
        }
        if (best)
            return *best;
        return std::nullopt;
    }

} // namespace vnet::routing
