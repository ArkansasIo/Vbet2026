#pragma once
#include <cstdint>
#include <string>

namespace vnet::protocol {
enum class ProtocolId : std::uint16_t { Ethernet=1, Arp=0x0806, IPv4=0x0800, Icmp=1, Udp=17, Tcp=6, Dhcp=67, Dns=53 };
struct ProtocolInfo { ProtocolId id; std::string name; std::string description; };
}
