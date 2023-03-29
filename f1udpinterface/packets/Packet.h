#pragma once

#include <array>
#include <cstdint>

namespace F122::Network::Packets {
    struct Packet {
        template<size_t NETWORK_PACKET_SIZE>
        explicit constexpr Packet(const std::array<std::uint8_t, NETWORK_PACKET_SIZE>&) {};

        virtual ~Packet() = 0;
    };
}
