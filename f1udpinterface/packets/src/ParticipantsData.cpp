#include "../ParticipantsData.h"
#include "../../../util.h"

namespace F122::Network::Packets {
    ParticipantsData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_aiControlled{bytes[0]},
            m_driverId{bytes[1]},
            m_networkId{bytes[2]},
            m_teamId{bytes[3]},
            m_myTeam{bytes[4]},
            m_raceNumber{bytes[5]},
            m_nationality{bytes[6]},
            m_name{util::convert_type(util::copy_resize<std::uint8_t, SIZE, 48, 7>(bytes))},
            m_yourTelemetry{bytes[55]} {}

    ParticipantsData::ParticipantsData(const std::array<std::uint8_t, SIZE>& bytes) :
            Packet(bytes),
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_numActiveCars{bytes[24]},
            m_participants{
                    util::batch_create<ParticipantsData::Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE + 1>(bytes)} {}


    ParticipantsData::~ParticipantsData() = default;

    std::string ParticipantsData::Data::name() const {
        auto i = std::find_if(m_name.begin(), m_name.end(), [](auto c) { return c == '\0'; });

        if (i == m_name.end()) {
            throw std::runtime_error("Could not find null character. Array: " + util::to_string(m_name));
        }

        return std::string{m_name.data()};
    }

    bool ParticipantsData::Data::is_ai_controlled() const {
        return m_aiControlled == 1;
    }

    std::ostream& operator<<(std::ostream& os, const ParticipantsData::Data& data) {
        os << "m_aiControlled: " << std::to_string(data.m_aiControlled) << "\n"
           << "m_driverId: " << std::to_string(data.m_driverId) << "\n"
           << "m_networkId: " << std::to_string(data.m_networkId) << "\n"
           << "m_teamId: " << std::to_string(data.m_teamId) << "\n"
           << "m_myTeam: " << std::to_string(data.m_myTeam) << "\n"
           << "m_raceNumber: " << std::to_string(data.m_raceNumber) << "\n"
           << "m_nationality: " << std::to_string(data.m_nationality) << "\n"
           << "m_yourTelemetry: " << std::to_string(data.m_yourTelemetry) << "\n"
           << "m_name: " << data.name() << " " << util::to_string(data.m_name);

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const ParticipantsData& data) {
        os << "m_header: " << "\n" << data.m_header
           << "m_numActiveCars: " << std::to_string(data.m_numActiveCars) << "\n"
           << "m_participants: " << "\n\n";

        for (size_t i = 0; i < data.m_participants.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_participants[i] << (i < data.m_participants.size() - 1 ? "\n\n" : "");
        }

        return os;
    }
}