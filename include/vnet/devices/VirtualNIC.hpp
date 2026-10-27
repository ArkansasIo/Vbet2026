#pragma once
#include <cstdint>
#include <string>

namespace vnet::devices
{

    class VirtualNIC
    {
    public:
        explicit VirtualNIC(std::uint64_t id = 0);
        std::uint64_t id() const noexcept { return id_; }
        void up() noexcept { up_ = true; }
        void down() noexcept { up_ = false; }
        bool isUp() const noexcept { return up_; }
        std::string name() const;

    private:
        std::uint64_t id_;
        bool up_{true};
    };

} // namespace vnet::devices
