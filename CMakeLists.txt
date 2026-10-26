cmake_minimum_required(VERSION 3.25)
project(VNet VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(VNET_BUILD_TESTS "Build tests" ON)

add_library(vnet
    src/address/IPv4.cpp
    src/core/Network.cpp
    src/devices/VirtualHost.cpp
    src/devices/VirtualNIC.cpp
    src/devices/VirtualSwitch.cpp
    src/devices/VirtualRouter.cpp
    src/routing/RoutingTable.cpp
    src/packet/Packet.cpp
    src/math/Number.cpp
    src/neural/NeuralNetwork.cpp
)

target_include_directories(vnet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(vnet PUBLIC cxx_std_23)

add_executable(vnet_demo examples/basic_network.cpp)
target_link_libraries(vnet_demo PRIVATE vnet)

if(VNET_BUILD_TESTS)
    enable_testing()
    add_executable(vnet_tests tests/basic_tests.cpp)
    target_link_libraries(vnet_tests PRIVATE vnet)
    add_test(NAME vnet_tests COMMAND vnet_tests)
endif()
