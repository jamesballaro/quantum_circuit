# Minimum required version of CMake
cmake_minimum_required(VERSION 3.16)

# Project name and C++ standard
project(quantum_circuit LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define paths
set(QT_DIR /opt/homebrew/Cellar/qt/6.7.3)
include_directories(${QT_DIR}/include ${QT_DIR}/include/QtWidgets include)

# Source and output directories
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(BUILD_DIR build)

# Enable AUTOMOC for meta-object compilation
set(CMAKE_AUTOMOC ON)

# Find Qt libraries
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Qml Quick QuickControls2)

# Add the source files
file(GLOB SRCS "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.h")

# Define the QML import path relative to the build directory
set(QML_IMPORT_DIR "${CMAKE_SOURCE_DIR}/${SRC_DIR}/qml")

qt_add_resources(RESOURCES ${SRC_DIR}/resources.qrc)
# Add the executable target
add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${RESOURCES})


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
#     #     ${SRC_DIR}/qml/icons/cnot.png
#     #     ${SRC_DIR}/qml/icons/cz.png
#     #     ${SRC_DIR}/qml/icons/pauli_x.png
#     #     ${SRC_DIR}/qml/icons/pauli_y.png
#     #     ${SRC_DIR}/qml/icons/pauli_z.png
#     #     ${SRC_DIR}/qml/icons/swap.png
#     #     ${SRC_DIR}/qml/icons/toffoli.png
#     NO_CACHEGEN
# )

target_compile_definitions(${PROJECT_NAME} PRIVATE QML2_IMPORT_PATH="${QML_IMPORT_DIR}")

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2)

# Output build files into the build directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}
)
# Custom clean command
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES ${BUILD_DIR})



