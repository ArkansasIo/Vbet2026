#include <cassert>
#include <iostream>
#include "vnet/address/IPv4.hpp"
#include "vnet/routing/RoutingTable.hpp"
#include "vnet/packet/Packet.hpp"
#include "vnet/math/Number.hpp"
#include "vnet/neural/NeuralNetwork.hpp"
#include "vnet/devices/VirtualHost.hpp"

int main()
{
    // IPv4 parsing and packing
    const auto ip = vnet::address::IPv4::parse("192.168.1.10");
    assert(ip.packed() == 0xC0A8010Au);
    assert(ip.toString() == "192.168.1.10");
    assert(ip.toPaddedDecimal9() == "000000192.000000168.000000001.000000010");

    // Routing: longest prefix match
    vnet::routing::RoutingTable table;
    table.add({vnet::address::IPv4::parse("0.0.0.0"), 0, 0x0A000001, 1});
    table.add({vnet::address::IPv4::parse("192.168.1.0"), 24, 0x0A000002, 1});
    const auto route = table.lookup(vnet::address::IPv4::parse("192.168.1.77"));
    assert(route && route->nextHop == 0x0A000002);

    // Packet summary
    vnet::packet::Packet p;
    p.id = 7;
    p.etherType = 0x0800;
    p.payload = {1, 2, 3, 4};
    assert(p.summary() == "id=7 etherType=0x0800 bytes=4");

    // 1024-bit math
    vnet::arch::UInt1024 a{}, b{};
    a.words[0] = 5;
    b.words[0] = 7;
    const auto sum = vnet::math::Number::add(a, b);
    assert(sum.words[0] == 12);
    assert(vnet::math::Number::toDecimal(sum) == "12");
    const auto diff = vnet::math::Number::subtract(sum, a);
    assert(diff.words[0] == 7);

    // Neural network
    vnet::neural::NeuralNetwork net("test");
    net.addNeuron({1, 0.0, 0.0, {}});
    assert(net.neuronCount() == 1);
    net.forward();
    net.backward();

    // Devices
    vnet::devices::VirtualHost host(1);
    host.addNIC(vnet::devices::VirtualNIC(0));
    host.addNIC(vnet::devices::VirtualNIC(1));
    assert(host.nicCount() == 2);

    std::cout << "All tests passed\n";
    return 0;
}
