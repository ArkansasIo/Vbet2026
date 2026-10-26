#include "vnet/core/Network.hpp"

namespace vnet::core {

std::shared_ptr<Node> Network::createNode(std::string name) {
    auto node = std::make_shared<Node>(nextId_++, std::move(name));
    nodes_.push_back(node);
    return node;
}

} // namespace vnet::core
