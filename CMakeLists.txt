cmake_minimum_required(VERSION 3.16)

project(CanConGrafica VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Aggiungi il percorso per le librerie e gli header di canlib
include_directories("C:/Program Files (x86)/Kvaser/Canlib/INC")
link_directories("C:/Program Files (x86)/Kvaser/Canlib/Lib/x64")

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CanConGrafica
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        tcanmxreader.h tcanmxreader.cpp
        globals.h
    )
else()
    add_executable(CanConGrafica
        ${PROJECT_SOURCES}
    )
endif()

# Link delle librerie Qt e canlib
target_link_libraries(CanConGrafica PRIVATE Qt${QT_VERSION_MAJOR}::Widgets canlib32.dll)

# Finalizzazione per Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CanConGrafica)
endif()

include(GNUInstallDirs)
install(TARGETS CanConGrafica
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
