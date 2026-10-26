#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace vnet::algorithms {
using Algorithm = std::function<double(const std::vector<double>&)>;
class AlgorithmRegistry {
public:
    void registerAlgorithm(std::string name, Algorithm algorithm);
    double execute(const std::string& name, const std::vector<double>& input) const;
    std::vector<std::string> names() const;
private:
    std::unordered_map<std::string, Algorithm> algorithms_;
};
}
