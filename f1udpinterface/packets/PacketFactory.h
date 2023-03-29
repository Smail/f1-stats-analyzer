#include <QByteArray>
#include <variant>
#include <memory>
#include "../public.h"

namespace F122::Network::Packets {
    using PacketVariant = std::variant<std::unique_ptr<CarDamageData>, std::unique_ptr<CarSetupData>,
            std::unique_ptr<CarStatusData>, std::unique_ptr<CarTelemetryData>, std::unique_ptr<EventData>,
            std::unique_ptr<FinalClassificationData>, std::unique_ptr<LapData>, std::unique_ptr<LobbyInfoData>,
            std::unique_ptr<MotionData>, std::unique_ptr<ParticipantsData>, std::unique_ptr<SessionData>,
            std::unique_ptr<SessionHistoryData>>;

    /// A factory to create the specific data structure from a given byte array.
    PacketVariant createPacket(const QByteArray& bytes);
}
