#include <chrono>
#include <iostream>
#include "../PacketFactory.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    PacketVariant createPacket(const QByteArray& bytes) {
        PacketVariant packetVariant{};

        // @formatter:off
        switch (bytes.size()) {
            case CarDamageData::SIZE:
                packetVariant = std::make_unique<CarDamageData>(util::copy_to_array<CarDamageData::SIZE>(bytes));
                break;
            case CarSetupData::SIZE:
                packetVariant = std::make_unique<CarSetupData>(util::copy_to_array<CarSetupData::SIZE>(bytes));
                break;
            case CarStatusData::SIZE:
                packetVariant = std::make_unique<CarStatusData>(util::copy_to_array<CarStatusData::SIZE>(bytes));
                break;
            case CarTelemetryData::SIZE:
                packetVariant = std::make_unique<CarTelemetryData>(util::copy_to_array<CarTelemetryData::SIZE>(bytes));
                break;
            case EventData::SIZE:
                packetVariant = std::make_unique<EventData>(util::copy_to_array<EventData::SIZE>(bytes));
                break;
            case FinalClassificationData::SIZE:
                packetVariant = std::make_unique<FinalClassificationData>(util::copy_to_array<FinalClassificationData::SIZE>(bytes));
                break;
            case LapData::SIZE:
                packetVariant = std::make_unique<LapData>(util::copy_to_array<LapData::SIZE>(bytes));
                break;
            case LobbyInfoData::SIZE:
                packetVariant = std::make_unique<LobbyInfoData>(util::copy_to_array<LobbyInfoData::SIZE>(bytes));
                break;
            case MotionData::SIZE:
                packetVariant = std::make_unique<MotionData>(util::copy_to_array<MotionData::SIZE>(bytes));
                break;
            case ParticipantsData::SIZE:
                packetVariant = std::make_unique<ParticipantsData>(util::copy_to_array<ParticipantsData::SIZE>(bytes));
                break;
            case SessionData::SIZE:
                packetVariant = std::make_unique<SessionData>(util::copy_to_array<SessionData::SIZE>(bytes));
                break;
            case SessionHistoryData::SIZE:
                packetVariant = std::make_unique<SessionHistoryData>(util::copy_to_array<SessionHistoryData::SIZE>(bytes));
                break;
            default:
                throw std::invalid_argument("Unknown byte size: The given byte array doesn't match any known type in this factory");
        }
        // @formatter:on

        return packetVariant;
    }
}
