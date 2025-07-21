cmake_minimum_required(VERSION 3.28)
project(GitFalcon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)

add_library(core STATIC
    src/repo.cpp
    src/api.cpp
    src/vector.cpp
    src/planner.cpp
    src/graph.cpp
    src/parser.cpp
)

target_include_directories(core PUBLIC header)
target_link_libraries(core
    PRIVATE
    Crow::Crow
    nlohmann_json::nlohmann_json
    fmt::fmt-header-only
)

add_executable(main src/main.cpp)
add_executable(tests tests/test_main.cpp)
target_link_libraries(main PRIVATE core)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)