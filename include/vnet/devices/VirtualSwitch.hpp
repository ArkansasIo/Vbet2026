#pragma once
#include "vnet/packet/Packet.hpp"
#include <cstdint>
#include <vector>

namespace vnet::devices
{

    class VirtualSwitch
    {
    public:
        explicit VirtualSwitch(std::uint64_t id = 0, std::size_t portCount = 8);
        std::size_t portCount() const noexcept { return portCount_; }
        void forward(const packet::Packet &packet);
        std::uint64_t framesForwarded() const noexcept { return frames_; }

    private:
        std::uint64_t id_;
        std::size_t portCount_;
        std::uint64_t frames_{0};
    };

} // namespace vnet::devices
