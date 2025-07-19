cmake_minimum_required(VERSION 3.28)
project(GitFalcon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(CURL CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

find_path(TREE_SITTER_INCLUDE_DIR tree_sitter/api.h REQUIRED)
find_library(TREE_SITTER_LIBRARY   NAMES tree-sitter REQUIRED)

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
    ${TREE_SITTER_LIBRARY}
    CURL::libcurl
    Crow::Crow
    nlohmann_json::nlohmann_json
    fmt::fmt-header-only
)

add_executable(main src/main.cpp)
add_executable(tests tests/test_main.cpp)
add_executable(indexer tools/indexer.cpp)
add_executable(query tools/query.cpp)

target_link_libraries(main indexer query PRIVATE core)
target_link_libraries(tests PRIVATE core Catch2::Catch2WithMain)

include(CTest)
catch_discover_tests(tests)