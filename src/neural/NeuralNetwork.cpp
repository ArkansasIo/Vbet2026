#include "vnet/neural/NeuralNetwork.hpp"
#include <cmath>

namespace vnet::neural {

void NeuralNetwork::forward() {
    for (auto& neuron : neurons_) {
        neuron.activation = 1.0 / (1.0 + std::exp(-neuron.activation - neuron.bias));
    }
}

void NeuralNetwork::backward() {
    for (auto& neuron : neurons_) {
        const double local = neuron.activation * (1.0 - neuron.activation);
        for (auto& weight : neuron.weights) weight.gradient = local * weight.value;
    }
}

} // namespace vnet::neural
