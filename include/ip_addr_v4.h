#pragma once

#include <algorithm>
#include <cstdint>

namespace ipv4
{
    struct ip_addr {
        ip_addr(const std::vector<std::string>& v)
        {
            std::transform(v.begin(), v.end(), std::back_inserter(octets),
                [](const std::string& s)
                    { return static_cast<uint8_t>(std::stoi(s)); });
        }

        uint32_t at(size_t index) const {
            return octets[index];
        }

        bool has(uint8_t any_octet) const {
            for(const auto& o: octets) {
                if (o == any_octet) return true;
            }
            return false;
        }

        void print() const
        {
            std::printf("%d.%d.%d.%d", octets[0], octets[1], octets[2], octets[3]);
            std::cout << std::endl;
        }

        uint32_t to_uint32() const
        {
            return static_cast<uint32_t>(
                octets[3] |
                octets[2] << 8 |
                octets[1] << 16 |
                octets[0] << 24 );
        }

        std::vector<uint8_t> octets;
    };
}
