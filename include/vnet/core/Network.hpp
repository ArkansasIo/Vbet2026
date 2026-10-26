#pragma once
#include "vnet/address/IPv4.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace vnet::core {

class Node {
public:
    using ID = std::uint64_t;
    explicit Node(ID id, std::string name) : id_(id), name_(std::move(name)) {}
    virtual ~Node() = default;
    ID id() const noexcept { return id_; }
    const std::string& name() const noexcept { return name_; }
private:
    ID id_;
    std::string name_;
};

class Network {
public:
    std::shared_ptr<Node> createNode(std::string name);
    const std::vector<std::shared_ptr<Node>>& nodes() const noexcept { return nodes_; }
private:
    std::uint64_t nextId_{1};
    std::vector<std::shared_ptr<Node>> nodes_;
};

} // namespace vnet::core
