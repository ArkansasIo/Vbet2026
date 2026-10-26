#include <cassert>
#include "vnet/address/IPv4.hpp"
#include "vnet/math/UInt1024.hpp"
int main() {
    const auto ip = vnet::address::IPv4::parse("192.168.1.10");
    assert(ip.packed() == 0xC0A8010Au);
    vnet::math::UInt1024 value{};
    value.words[0] = 42;
    assert(value.words[0] == 42);
}
