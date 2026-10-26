#pragma once
#include <cstdint>
#include <vector>
#include <optional>
#include "vnet/address/IPv4.hpp"

namespace vnet::routing {
struct Route { address::IPv4 network; std::uint8_t prefix{}; std::uint32_t nextHop{}; std::uint32_t metric{1}; };
class RoutingTable {
public:
    void add(Route route);
    std::optional<Route> lookup(address::IPv4 address) const;
    const std::vector<Route>& routes() const noexcept { return routes_; }
private:
    std::vector<Route> routes_;
};
}
