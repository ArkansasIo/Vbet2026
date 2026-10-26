#pragma once
#include <cstddef>
#include <vector>

namespace vnet::neural {
class Neuron {
public:
    explicit Neuron(std::size_t inputs = 0);
    double forward(const std::vector<double>& inputs) const;
    std::vector<double>& weights() noexcept { return weights_; }
    const std::vector<double>& weights() const noexcept { return weights_; }
    double& bias() noexcept { return bias_; }
private:
    std::vector<double> weights_;
    double bias_{0.0};
};
}
