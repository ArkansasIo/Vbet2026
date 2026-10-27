#include "vnet/core/Network.hpp"
#include "vnet/address/IPv4.hpp"
#include "vnet/devices/VirtualHost.hpp"
#include "vnet/devices/VirtualSwitch.hpp"
#include "vnet/devices/VirtualRouter.hpp"
#include "vnet/packet/Packet.hpp"
#include "vnet/math/Number.hpp"
#include "vnet/neural/NeuralNetwork.hpp"
#include <iostream>

int main()
{
    vnet::core::Network network;
    auto node = network.createNode("host-a");
    std::cout << "Created node " << node->id() << ": " << node->name() << '\n';

    const auto ip = vnet::address::IPv4(192, 168, 1, 10);
    std::cout << "IP: " << ip.toString() << "  padded9: " << ip.toPaddedDecimal9() << '\n';

    vnet::devices::VirtualHost host(1);
    host.addNIC(vnet::devices::VirtualNIC(0));
    std::cout << "Host NICs: " << host.nicCount() << '\n';

    vnet::devices::VirtualSwitch sw(2, 8);
    vnet::packet::Packet packet;
    packet.id = 1;
    packet.etherType = 0x0800;
    packet.payload = {0x01, 0x02, 0x03};
    sw.forward(packet);
    std::cout << "Packet: " << packet.summary() << "  frames forwarded: " << sw.framesForwarded() << '\n';

    vnet::devices::VirtualRouter router(3);
    router.routingTable().add({vnet::address::IPv4(192, 168, 1, 0), 24, 0x0A000001, 1});
    std::cout << "Next hop for 192.168.1.77: 0x" << std::hex << router.resolveNextHop(ip.packed()) << std::dec << '\n';

    vnet::arch::UInt1024 big{};
    big.words[0] = 1;
    const auto sum = vnet::math::Number::add(big, big);
    std::cout << "1024-bit 1+1 = " << vnet::math::Number::toDecimal(sum) << '\n';

    vnet::neural::NeuralNetwork net("demo");
    vnet::neural::Neuron n{1, 0.5, 0.25, {{2, 3, 0.75, 0.0}}};
    net.addNeuron(n);
    net.forward();
    net.backward();
    std::cout << "Neurons: " << net.neuronCount() << '\n';

    return 0;
}
