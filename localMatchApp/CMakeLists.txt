CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Project name and language of it
PROJECT(local_match
  LANGUAGES CXX)

# Find includes in corresponding build directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
SET(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
SET(CMAKE_AUTOUIC OFF)

# Find the QtWidgets library
FIND_PACKAGE(Qt5Widgets CONFIG REQUIRED)

# Include directories of sources and headers
INCLUDE_DIRECTORIES(sources headers)

# Set a list of files with the name code_SOURCES that includes .cpp files
FILE(GLOB code_SOURCES
  "sources/*.cpp"
  "*.cpp")

# Set a list of files with the name code_HEADERS that includes .h files
FILE(GLOB code_HEADERS
  "headers/*.h")

# Set a list of files with the name code_FORMS that includes .ui files
FILE(GLOB code_FORMS
  "forms/*.ui")

# Set a list of files with the name code_RESOURCES that includes .qrc files
FILE(GLOB code_RESOURCES
  "resources/*.qrc")

# Create moc code from header files and another from forms
QT5_WRAP_CPP(code_HEADERS_MOC ${code_HEADERS})
QT5_WRAP_UI(code_FORMS_HEADERS ${code_FORMS})

# Create code from a list of Qt resource files
QT5_ADD_RESOURCES(code_RESOURCES_RCC ${code_RESOURCES})

ADD_EXECUTABLE(local_match ${code_SOURCES}
  ${code_HEADERS_MOC}
  ${code_FORMS_HEADERS}
  ${code_RESOURCES_RCC})

TARGET_LINK_LIBRARIES(local_match Qt5::Widgets)
