#pragma once

#include <array>
#include <cstdint>

namespace F122::Network::Packets {
    class Packet {
    public:
        template<size_t NETWORK_PACKET_SIZE>
        explicit Packet(const std::array<std::uint8_t, NETWORK_PACKET_SIZE>& bytes) :
                expectedPacketSize{NETWORK_PACKET_SIZE} {}

        virtual ~Packet() = 0;

        [[nodiscard]] size_t getExpectedPacketSize() const;

    private:
        /// The size of the network packet this class represents in bytes.
        const size_t expectedPacketSize;
    };
}
