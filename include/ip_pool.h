#pragma once

#include <algorithm>
#include <cstdint>
#include "ip_addr_v4.h"

namespace ipv4
{
    struct ip_addr_pool {

        void add(ip_addr& addr) {
            pool.push_back(addr);
        }

        void finalize() {
            std::sort(pool.begin(), pool.end(), [](ip_addr& a, ip_addr& b)
                    { return a.to_uint32() > b.to_uint32(); });
        }

        void print() {
            for(const auto& addr: pool) {
                addr.print();
            }
        }

        template<typename FilterFunc>
        void print_filtered(FilterFunc filter_func) {
            for(const auto& addr: pool) {
                if (filter_func(addr)) {
                    addr.print();
                }
            }
        }

        std::vector<ip_addr> pool;
    };
}
