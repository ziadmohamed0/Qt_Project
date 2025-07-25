cmake_minimum_required(VERSION 3.10)
project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    Data/Data.cpp
    Curl/Curl.cpp
    Rapidjson/Rapidjson.cpp
    Cities/Cities.cpp
)

find_package(CURL REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    Data
    Curl
    DataAbstract
    CurlAbstract
    RapidjsonAbstract
    Rapidjson
    Cities
    ${CURL_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})
