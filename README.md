# VNet / Vbet2026

C++23 virtual network and computational simulation platform.

## Architecture

- Virtual hosts, nodes, switches, routers and packets
- IPv4 addressing with fixed nine-digit decimal display per octet
- Native 64-bit computation
- Virtual 1024-bit values represented by 16 x 64-bit words (128 bytes)
- Neural-network primitives with neurons, weights, biases and gradients
- Extensible algorithm and mathematics subsystems
- MySQL persistence with Excel/CSV/JSON backend interchange
- Control-center UI architecture for network and neural visualization

## Build

```bash
cmake -S . -B build -DVNET_BUILD_TESTS=ON
cmake --build build
ctest --test-dir build
```

The project is intentionally modular: protocol, routing, algorithm, database, configuration and UI modules can be added without changing the core public API.
