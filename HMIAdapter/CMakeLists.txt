cmake_minimum_required(VERSION 3.14)
project(HMIAdapter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core DBus)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(HMIAdapter SHARED ${SOURCES} ${HEADERS})

target_include_directories(HMIAdapter
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(HMIAdapter
    PRIVATE Qt5::Core Qt5::DBus
)

# Optional export target for use in main app
install(TARGETS HMIAdapter EXPORT HMIAdapterTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)

