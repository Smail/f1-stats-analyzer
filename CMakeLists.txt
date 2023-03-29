cmake_minimum_required(VERSION 3.24)
project(f1_22_stats)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        OpenGLWidgets
        Network
        Charts
        REQUIRED)

set(FILES f1udpinterface/packets/PacketHeader.h f1udpinterface/packets/SessionData.h
        f1udpinterface/packets/MotionData.h f1udpinterface/packets/EventData.h f1udpinterface/packets/LapData.h
        f1udpinterface/packets/ParticipantsData.h f1udpinterface/packets/CarSetupData.h f1udpinterface/packets/FinalClassificationData.h
        f1udpinterface/packets/LobbyInfoData.h f1udpinterface/packets/CarDamageData.h f1udpinterface/packets/CarStatusData.h
        f1udpinterface/ids/TeamId.h f1udpinterface/ids/DriverId.h f1udpinterface/ids/TrackId.h f1udpinterface/ids/NationalityId.h
        f1udpinterface/ids/RulesetId.h f1udpinterface/ids/SurfaceTypeId.h f1udpinterface/ids/PenaltyTypeId.h
        f1udpinterface/ids/InfringementTypeId.h f1udpinterface/ids/ButtonFlags.h f1udpinterface/ids/GameModeId.h
        f1udpinterface/packets/CarTelemetryData.h f1udpinterface/packets/SessionHistoryData.h
        f1udpinterface/public.h util.h f1udpinterface/packets/src/PacketHeader.cpp
        f1udpinterface/packets/src/CarDamageData.cpp f1udpinterface/packets/src/CarSetupData.cpp
        f1udpinterface/packets/src/CarTelemetryData.cpp f1udpinterface/packets/src/EventData.cpp
        f1udpinterface/packets/src/FinalClassificationData.cpp f1udpinterface/packets/src/LobbyInfoData.cpp
        f1udpinterface/packets/src/MotionData.cpp f1udpinterface/packets/src/ParticipantsData.cpp
        f1udpinterface/packets/src/SessionData.cpp f1udpinterface/packets/src/LapData.cpp
        f1udpinterface/packets/src/CarStatusData.cpp f1udpinterface/ids/src/DriverId.cpp
        f1udpinterface/ids/src/ButtonFlags.cpp f1udpinterface/ids/src/GameModeId.cpp
        f1udpinterface/ids/src/InfringementTypeId.cpp f1udpinterface/ids/src/NationalityId.cpp
        f1udpinterface/ids/src/PenaltyTypeId.cpp f1udpinterface/ids/src/RulesetId.cpp
        f1udpinterface/ids/src/SurfaceTypeId.cpp f1udpinterface/ids/src/TeamId.cpp f1udpinterface/ids/src/TrackId.cpp
        f1udpinterface/packets/Packet.h f1udpinterface/packets/src/Packet.cpp gui/CarActivationButton.cpp gui/CarActivationButton.h gui/TeamColorMapping.h gui/TeamColorMapping.cpp gui/Worker.cpp gui/Worker.h f1udpinterface/packets/src/PacketFactory.cpp f1udpinterface/packets/PacketFactory.h )

add_executable(${PROJECT_NAME} main.cpp ${FILES} f1udpinterface/packets/src/SessionHistoryData.cpp)

add_executable(${PROJECT_NAME}_test test/main.cpp ${FILES})

target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::OpenGLWidgets
        Qt::Network
        Qt::Charts
        )

target_link_libraries(${PROJECT_NAME}_test
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::OpenGLWidgets
        Qt::Network
        Qt::Charts
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
