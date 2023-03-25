#pragma once

#include <array>
#include <cstdint>

namespace F122::Network::Packets {
    class Packet {
    public:
        template<size_t NETWORK_PACKET_SIZE>
        explicit constexpr Packet(const std::array<std::uint8_t, NETWORK_PACKET_SIZE>&) :
                expectedPacketSize{NETWORK_PACKET_SIZE} {}

        virtual ~Packet() = 0;

    public:
        /// The size of the network packet this class represents in bytes.
        const size_t expectedPacketSize;
    };
}
