#ifndef VNET_CORE_LOGGER_HPP
#define VNET_CORE_LOGGER_HPP

#include <iostream>
#include <string>

namespace vnet
{
    namespace core
    {

        class Logger
        {
        public:
            static void Initialize()
            {
                std::cout << "Logger initialized." << std::endl;
            }

            static void Info(const std::string &message)
            {
                std::cout << "[INFO] " << message << std::endl;
            }

            static void Error(const std::string &message)
            {
                std::cerr << "[ERROR] " << message << std::endl;
            }
        };

    } // namespace core
} // namespace vnet

#endif // VNET_CORE_LOGGER_HPP