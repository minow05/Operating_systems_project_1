cmake_minimum_required(VERSION 3.31)
project(Operating_systems_project_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(SFML googletest)

# Add the main executable
add_executable(Operating_systems_project_1
        src/main.cpp
        src/Quick.cpp
        include/Algorithms/SortingAlgorithm.h
        include/UI/Button.h
        include/Algorithms/QuickMultithread.hpp
        src/QuickMultithread.cpp
)

target_include_directories(Operating_systems_project_1 PRIVATE include)

target_link_libraries(Operating_systems_project_1 PRIVATE SFML::Graphics)

enable_testing()

add_executable(tests
        tests/test_sizeOneArray.cpp
        src/Quick.cpp
        tests/test_DataGeneration.cpp
        include/Algorithms/QuickMultithread.hpp
        src/QuickMultithread.cpp
)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests PRIVATE GTest::gtest_main SFML::Graphics)

include(GoogleTest)
gtest_discover_tests(tests)
