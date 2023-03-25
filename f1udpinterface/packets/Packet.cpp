#include "Packet.h"

namespace F122::Network::Packets {
    Packet::~Packet() = default;

    size_t Packet::getExpectedPacketSize() const {
        return expectedPacketSize;
    }
}
