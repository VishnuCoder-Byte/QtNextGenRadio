cmake_minimum_required(VERSION 3.14)
project(MyQtApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt's automoc to generate MOC files
set(CMAKE_AUTOMOC ON)

# Qt modules needed
find_package(Qt5 REQUIRED COMPONENTS Core Gui Qml DBus)

# Source files from all directories
set(SOURCES
    main.cpp
    controller/RadioController.cpp
    model/RadioModel.cpp
)

# Headers that contain Q_OBJECT macros (must be explicitly listed!)
set(HEADERS
    controller/RadioController.h
    model/RadioModel.h
)

# Add the executable
add_executable(MyQtApp ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(MyQtApp
    PRIVATE
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/model
        ${CMAKE_SOURCE_DIR}/../HMIAdapter/include
)

# Add subdirectory
add_subdirectory(../HMIAdapter build)

# Link to the target
target_link_libraries(MyQtApp
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
        Qt5::DBus
        HMIAdapter
)


