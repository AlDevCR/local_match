CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Project name and language of it
PROJECT(local_match)

# Enable standard C++ 14 compiler
SET(CMAKE_CXX_STANDARD 14)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)

# Find includes in corresponding build directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
SET(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
SET(CMAKE_AUTOUIC OFF)

# Find the QtWidgets library
FIND_PACKAGE(Qt5Widgets CONFIG REQUIRED)
FIND_PACKAGE(Qt5Sql)

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

TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Widgets Qt5::Sql)

###################################################################
# Gtest section

# Create a variable with the name of the project and "_test"
SET(TEST_LOCAL_MATCH ${PROJECT_NAME}_test)

# Define the code language as C++ 14
ADD_DEFINITIONS(-DGTEST_LANGUAGE_CXX14)

# Search for a package required for executing gtest
find_package(Threads REQUIRED)

# Set the direction of the gtest repository
IF ($ENV{GOOGLETEST_DIR})
		SET(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
ELSE ()
		MESSAGE(WARNING "Using googletest src dir specified in line 74")
		SET(GOOGLETEST_DIR "/app/googletest")
ENDIF ()

# If it finds the gtest files, put it in a variable.
IF (EXISTS ${GOOGLETEST_DIR})
		SET(GTestSrc ${GOOGLETEST_DIR}/googletest)
		SET(GMockSrc ${GOOGLETEST_DIR}/googlemock)
ELSE ()
		MESSAGE( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
ENDIF ()
INCLUDE_DIRECTORIES(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)

# Find the QT widgets package
FIND_PACKAGE(Qt5Widgets CONFIG REQUIRED)

# Set a list of files with the name test_FILES that includes .h files
FILE(GLOB test_FILES
	"test/*.cpp")

# Include the .cpp files without the main of the main project
FILE(GLOB test_SOURCES
	"sources/*.cpp")

ADD_EXECUTABLE(${TEST_LOCAL_MATCH} ${test_FILES}
	${GTestSrc}/src/gtest-all.cc
	${GMockSrc}/src/gmock-all.cc
	${test_SOURCES}
	${code_HEADERS_MOC}
	)

ADD_TEST(${TEST_LOCAL_MATCH} COMMAND ${TEST_LOCAL_MATCH})
TARGET_LINK_LIBRARIES(${TEST_LOCAL_MATCH} PRIVATE Threads::Threads Qt5::Widgets Qt5::Sql)
###################################################################
