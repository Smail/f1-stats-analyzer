#pragma once

/// Each packet carries different types of data rather than having one packet which contains everything. The
/// header in each packet describes the packet type and versioning info so it will be easier for applications
/// to check they are interpreting the incoming data in the correct way. Please note that all values are
/// encoded using Little Endian format. All data is packed.<br>
/// <br>
/// During a session, each car is assigned a vehicle index.
/// This will not change throughout the session and
/// all the arrays that are sent use this vehicle index to dereference the correct piece of data.

#include "packets/PacketHeader.h"
#include "packets/PacketMotionData.h"
#include "packets/PacketSessionData.h"
#include "packets/PacketLapData.h"
#include "packets/PacketEventData.h"
#include "packets/PacketParticipantsData.h"
#include "packets/PacketCarSetupData.h"
#include "packets/PacketCarTelemetryData.h"
#include "packets/PacketCarStatusData.h"
#include "packets/PacketFinalClassificationData.h"
#include "packets/PacketLobbyInfoData.h"
#include "packets/PacketCarDamageData.h"
#include "packets/PacketSessionHistoryData.h"
