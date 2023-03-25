#include "MotionData.h"
#include "../../util.h"

namespace F122::Network::Packets {
    MotionData::MotionData(const std::array<std::uint8_t, SIZE>& bytes) :
            m_header{{util::copy_resize<std::uint8_t, SIZE, PacketHeader::SIZE>(bytes)}},
            m_carMotionData{util::batch_create<Data, SIZE, Data::SIZE, 22, PacketHeader::SIZE>(bytes)},
            m_suspensionPosition{
                    util::convert<float>({bytes[1344], bytes[1345], bytes[1346], bytes[1347]}),
                    util::convert<float>({bytes[1348], bytes[1349], bytes[1350], bytes[1351]}),
                    util::convert<float>({bytes[1352], bytes[1353], bytes[1354], bytes[1355]}),
                    util::convert<float>({bytes[1356], bytes[1357], bytes[1358], bytes[1359]}),
            },
            m_suspensionVelocity{
                    util::convert<float>({bytes[1360], bytes[1361], bytes[1362], bytes[1363]}),
                    util::convert<float>({bytes[1364], bytes[1365], bytes[1366], bytes[1367]}),
                    util::convert<float>({bytes[1368], bytes[1369], bytes[1370], bytes[1371]}),
                    util::convert<float>({bytes[1372], bytes[1373], bytes[1374], bytes[1375]}),
            },
            m_suspensionAcceleration{
                    util::convert<float>({bytes[1376], bytes[1377], bytes[1378], bytes[1379]}),
                    util::convert<float>({bytes[1380], bytes[1381], bytes[1382], bytes[1383]}),
                    util::convert<float>({bytes[1384], bytes[1385], bytes[1386], bytes[1387]}),
                    util::convert<float>({bytes[1388], bytes[1389], bytes[1390], bytes[1391]}),
            },
            m_wheelSpeed{
                    util::convert<float>({bytes[1392], bytes[1393], bytes[1394], bytes[1395]}),
                    util::convert<float>({bytes[1396], bytes[1397], bytes[1398], bytes[1399]}),
                    util::convert<float>({bytes[1400], bytes[1401], bytes[1402], bytes[1403]}),
                    util::convert<float>({bytes[1404], bytes[1405], bytes[1406], bytes[1407]}),
            },
            m_wheelSlip{
                    util::convert<float>({bytes[1408], bytes[1409], bytes[1410], bytes[1411]}),
                    util::convert<float>({bytes[1412], bytes[1413], bytes[1414], bytes[1415]}),
                    util::convert<float>({bytes[1416], bytes[1417], bytes[1418], bytes[1419]}),
                    util::convert<float>({bytes[1420], bytes[1421], bytes[1422], bytes[1423]}),
            },
            m_localVelocityX{util::convert<float>({bytes[1424], bytes[1425], bytes[1426], bytes[1427]})},
            m_localVelocityY{util::convert<float>({bytes[1428], bytes[1429], bytes[1430], bytes[1431]})},
            m_localVelocityZ{util::convert<float>({bytes[1432], bytes[1433], bytes[1434], bytes[1435]})},
            m_angularVelocityX{util::convert<float>({bytes[1436], bytes[1437], bytes[1438], bytes[1439]})},
            m_angularVelocityY{util::convert<float>({bytes[1440], bytes[1441], bytes[1442], bytes[1443]})},
            m_angularVelocityZ{util::convert<float>({bytes[1444], bytes[1445], bytes[1446], bytes[1447]})},
            m_angularAccelerationX{util::convert<float>({bytes[1448], bytes[1449], bytes[1450], bytes[1451]})},
            m_angularAccelerationY{util::convert<float>({bytes[1452], bytes[1453], bytes[1454], bytes[1455]})},
            m_angularAccelerationZ{util::convert<float>({bytes[1456], bytes[1457], bytes[1458], bytes[1459]})},
            m_frontWheelsAngle{util::convert<float>({bytes[1460], bytes[1461], bytes[1462], bytes[1463]})} {}

    MotionData::Data::Data(const std::array<std::uint8_t, SIZE>& bytes) :
            m_worldPositionX{util::convert<float>({bytes[0], bytes[1], bytes[2], bytes[3]})},
            m_worldPositionY{util::convert<float>({bytes[4], bytes[5], bytes[6], bytes[7]})},
            m_worldPositionZ{util::convert<float>({bytes[8], bytes[9], bytes[10], bytes[11]})},
            m_worldVelocityX{util::convert<float>({bytes[12], bytes[13], bytes[14], bytes[15]})},
            m_worldVelocityY{util::convert<float>({bytes[16], bytes[17], bytes[18], bytes[19]})},
            m_worldVelocityZ{util::convert<float>({bytes[20], bytes[21], bytes[22], bytes[23]})},
            m_worldForwardDirX{util::convert<std::int16_t>({bytes[24], bytes[25]})},
            m_worldForwardDirY{util::convert<std::int16_t>({bytes[26], bytes[27]})},
            m_worldForwardDirZ{util::convert<std::int16_t>({bytes[28], bytes[29]})},
            m_worldRightDirX{util::convert<std::int16_t>({bytes[30], bytes[31]})},
            m_worldRightDirY{util::convert<std::int16_t>({bytes[32], bytes[33]})},
            m_worldRightDirZ{util::convert<std::int16_t>({bytes[34], bytes[35]})},
            m_gForceLateral{util::convert<float>({bytes[36], bytes[37], bytes[38], bytes[39]})},
            m_gForceLongitudinal{util::convert<float>({bytes[40], bytes[41], bytes[42], bytes[43]})},
            m_gForceVertical{util::convert<float>({bytes[44], bytes[45], bytes[46], bytes[47]})},
            m_yaw{util::convert<float>({bytes[48], bytes[49], bytes[50], bytes[51]})},
            m_pitch{util::convert<float>({bytes[52], bytes[53], bytes[54], bytes[55]})},
            m_roll{util::convert<float>({bytes[56], bytes[57], bytes[58], bytes[59]})} {}

    std::ostream& operator<<(std::ostream& os, const MotionData::Data& data) {
        os << "m_worldPositionX: " << std::to_string(data.m_worldPositionX) << "\n"
           << "m_worldPositionY: " << std::to_string(data.m_worldPositionY) << "\n"
           << "m_worldPositionZ: " << std::to_string(data.m_worldPositionZ) << "\n"
           << "m_worldVelocityX: " << std::to_string(data.m_worldVelocityX) << "\n"
           << "m_worldVelocityY: " << std::to_string(data.m_worldVelocityY) << "\n"
           << "m_worldVelocityZ: " << std::to_string(data.m_worldVelocityZ) << "\n"
           << "m_worldForwardDirX: " << std::to_string(data.m_worldForwardDirX) << "\n"
           << "m_worldForwardDirY: " << std::to_string(data.m_worldForwardDirY) << "\n"
           << "m_worldForwardDirZ: " << std::to_string(data.m_worldForwardDirZ) << "\n"
           << "m_worldRightDirX: " << std::to_string(data.m_worldRightDirX) << "\n"
           << "m_worldRightDirY: " << std::to_string(data.m_worldRightDirY) << "\n"
           << "m_worldRightDirZ: " << std::to_string(data.m_worldRightDirZ) << "\n"
           << "m_gForceLateral: " << std::to_string(data.m_gForceLateral) << "\n"
           << "m_gForceLongitudinal: " << std::to_string(data.m_gForceLongitudinal) << "\n"
           << "m_gForceVertical: " << std::to_string(data.m_gForceVertical) << "\n"
           << "m_yaw: " << std::to_string(data.m_yaw) << "\n"
           << "m_pitch: " << std::to_string(data.m_pitch) << "\n"
           << "m_roll: " << std::to_string(data.m_roll) << "\n";

        return os;
    }

    std::ostream& operator<<(std::ostream& os, const MotionData& data) {
        os << "m_header: " << "\n" << data.m_header << "\n"
           << "m_suspensionPosition: " << util::to_string(data.m_suspensionPosition) << "\n"
           << "m_suspensionVelocity: " << util::to_string(data.m_suspensionVelocity) << "\n"
           << "m_suspensionAcceleration: " << util::to_string(data.m_suspensionAcceleration) << "\n"
           << "m_wheelSpeed: " << util::to_string(data.m_wheelSpeed) << "\n"
           << "m_wheelSlip: " << util::to_string(data.m_wheelSlip) << "\n"
           << "m_localVelocityX: " << std::to_string(data.m_localVelocityX) << "\n"
           << "m_localVelocityY: " << std::to_string(data.m_localVelocityY) << "\n"
           << "m_localVelocityZ: " << std::to_string(data.m_localVelocityZ) << "\n"
           << "m_angularVelocityX: " << std::to_string(data.m_angularVelocityX) << "\n"
           << "m_angularVelocityY: " << std::to_string(data.m_angularVelocityY) << "\n"
           << "m_angularVelocityZ: " << std::to_string(data.m_angularVelocityZ) << "\n"
           << "m_angularAccelerationX: " << std::to_string(data.m_angularAccelerationX) << "\n"
           << "m_angularAccelerationY: " << std::to_string(data.m_angularAccelerationY) << "\n"
           << "m_angularAccelerationZ: " << std::to_string(data.m_angularAccelerationZ) << "\n"
           << "m_frontWheelsAngle: " << std::to_string(data.m_frontWheelsAngle) << "\n"
           << "m_carMotionData: " << "\n\n";

        for (size_t i = 0; i < data.m_carMotionData.size(); ++i) {
            os << "Car " << std::to_string(i) << ": " << "\n";
            os << data.m_carMotionData[i] << (i < data.m_carMotionData.size() - 1 ? "\n" : "");
        }

        return os;
    }
}
