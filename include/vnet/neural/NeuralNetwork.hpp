#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace vnet::neural {

struct Weight {
    std::uint64_t source{};
    std::uint64_t target{};
    double value{};
    double gradient{};
};

struct Neuron {
    std::uint64_t id{};
    double bias{};
    double activation{};
    std::vector<Weight> weights;
};

class NeuralNetwork {
public:
    explicit NeuralNetwork(std::string name = "network") : name_(std::move(name)) {}
    void addNeuron(Neuron neuron) { neurons_.push_back(std::move(neuron)); }
    void forward();
    void backward();
    std::size_t neuronCount() const noexcept { return neurons_.size(); }
    const std::vector<Neuron>& neurons() const noexcept { return neurons_; }
private:
    std::string name_;
    std::vector<Neuron> neurons_;
};

} // namespace vnet::neural
