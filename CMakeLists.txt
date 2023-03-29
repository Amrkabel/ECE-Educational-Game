cmake_minimum_required(VERSION 3.5)

project(ECE_Game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        programming_levels.h
        programming_levels.cpp
        programming_levels.ui

        progguilevel1.h
        progguilevel1.cpp
        progguilevel1.ui

        digitallevels.h
        digitallevels.cpp
        digitallevels.ui

        digitallevel1.h
        digitallevel1.cpp
        digitallevel1.ui

        digitallevel2.h
        digitallevel2.cpp
        digitallevel2.ui

        circuitlevels.h
        circuitlevels.cpp
        circuitlevels.ui

        Nodes.h
        Gates.h
        DigitalLogic.h
        DigitalLogicLevel1.h
        Programming.h

        res.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ECE_Game
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ECE_Game APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ECE_Game SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ECE_Game
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ECE_Game PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(ECE_Game PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ECE_Game
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ECE_Game)
endif()
