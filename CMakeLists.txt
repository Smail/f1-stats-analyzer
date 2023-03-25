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
        f1udpinterface/public.h util.h f1udpinterface/packets/PacketHeader.cpp
        f1udpinterface/packets/CarDamageData.cpp f1udpinterface/packets/CarSetupData.cpp
        f1udpinterface/packets/CarTelemetryData.cpp f1udpinterface/packets/EventData.cpp
        f1udpinterface/packets/FinalClassificationData.cpp f1udpinterface/packets/LobbyInfoData.cpp
        f1udpinterface/packets/MotionData.cpp f1udpinterface/packets/ParticipantsData.cpp
        f1udpinterface/packets/SessionData.cpp f1udpinterface/packets/LapData.cpp
        f1udpinterface/packets/CarStatusData.cpp f1udpinterface/ids/DriverId.cpp f1udpinterface/ids/ButtonFlags.cpp f1udpinterface/ids/GameModeId.cpp f1udpinterface/ids/InfringementTypeId.cpp f1udpinterface/ids/NationalityId.cpp f1udpinterface/ids/PenaltyTypeId.cpp f1udpinterface/ids/RulesetId.cpp f1udpinterface/ids/SurfaceTypeId.cpp f1udpinterface/ids/TeamId.cpp f1udpinterface/ids/TrackId.cpp f1udpinterface/packets/Packet.h f1udpinterface/packets/Packet.cpp)

add_executable(${PROJECT_NAME} main.cpp ${FILES} f1udpinterface/packets/SessionHistoryData.cpp)

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
