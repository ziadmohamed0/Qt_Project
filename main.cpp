/**
 * @file main.cpp
 * @author Ziad Mohammed Fathy
 * @brief Main project file.
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Cities/Cities.h"
#include "Data/Data.h"
#include "Curl/Curl.h"
#include "Rapidjson/Rapidjson.h"

int main(void) {
    Cities c;
    c.AddCity("Cairo", "30.0444", "31.2357");
    c.AddCity("Alex", "31.2001", "29.9187");

    const std::string city = "Cairo";
    const auto [lat, lon] = c.GetAxis(city);

    Data data;
    Curl curl(lat, lon, &data);

    if (curl.Curl_init() != Curl_Status::SUCCESS ||
        curl.Curl_SetUp() != Curl_Status::SUCCESS ||
        curl.Curl_Perform() != Curl_Status::SUCCESS) {
        std::cerr << "Curl process failed\n";
        return EXIT_FAILURE;
    }

    Rapidjson parser(data.GetResponse());

    std::cout << "First temperature in " << city << ": " << parser.GetTemprature() << " °C\n";
    std::cout << "First time in " << city << ": " << parser.GetTime() << "\n";

    return EXIT_SUCCESS;
    return 0;
}