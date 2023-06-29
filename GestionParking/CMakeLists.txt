cmake_minimum_required(VERSION 3.5)

project(GESTIONPARKING VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        addpackage.h
        addpackage.cpp
        addpackage.ui
authentification.cpp
authentification.h
authentification.ui
#mainwindow1.cpp
#mainwindow1.h
#mainwindow1.ui

        finduser.h
        finduser.cpp
        finduser.ui
        findpackage.h
        findpackage.cpp
        findpackage.ui
        registeruser.cpp
        registeruser.h
        registeruser.ui
ajouterplace.cpp
ajouterplace.h
ajouterplace.ui

      placedispo.h
       placedispo.cpp
        placedispo.ui
        databaseheader.h
        resource.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GestionParking
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(GestionParking SHARED
            ${PROJECT_SOURCES}
        )

    else()
        add_executable(GestionParking
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GestionParking PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  Qt${QT_VERSION_MAJOR}::Sql)

set_target_properties(GestionParking PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS GestionParking
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GestionParking)
endif()
