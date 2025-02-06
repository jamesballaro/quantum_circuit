# Minimum required version of CMake
cmake_minimum_required(VERSION 3.16)

# Project name and C++ standard
project(quantum_circuit LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define paths
set(QT_DIR /opt/homebrew/Cellar/qt/6.7.3)
include_directories(${QT_DIR}/include ${QT_DIR}/include/QtWidgets include)
set(QT_QML_GENERATE_QMLLS_INI ON)
# Source and output directories
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(BUILD_DIR build)

# Enable AUTOMOC for meta-object compilation
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON) # Ensure Qt resources (*.qrc) are processed automatically
set(CMAKE_AUTOUIC ON) # Enable support for Qt Designer files (*.ui), if needed

# Find Qt libraries
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Qml Quick QuickControls2)

# Add the source files
file(GLOB SRCS "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.h")

add_compile_definitions(QML2_IMPORT_PATH="${CMAKE_SOURCE_DIR}/src/qml")

qt_add_resources(RESOURCES src/resources.qrc)

# Add the executable target
add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${RESOURCES})

set(QML2_IMPORT_PATH ${QML2_IMPORT_PATH}
    FORCE
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2)

# Output build files into the build directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}
)
# Custom clean command
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${BUILD_DIR})

# #Add the QML module with hot-reload enabled
# qt_add_qml_module(${PROJECT_NAME}
#     URI "QuantumCircuit.UI"
#     VERSION 1.0
#     QML_FILES
#         ${SRC_DIR}/qml/main.qml
#         ${SRC_DIR}/qml/components/pButton.qml
#         ${SRC_DIR}/qml/components/GateIcon.qml
#     # RESOURCES
#     #     ${SRC_DIR}/qml/icons/hadamard.png
#     NO_CACHEGEN
# )
