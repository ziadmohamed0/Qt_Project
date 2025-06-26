/**
 * @file cities.cpp
 * @author Ziad Mohammed Fathy
 * @brief Cities defination file
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "cities.h"

/**
 * @brief 
 * 
 * @param name 
 * @param latitiude 
 * @param longtiude 
 */
void cities::AddCity(std::string name, std::string latitiude, std::string longtiude) {
    this->cities[name] = {latitiude, longtiude};
}

/**
 * @brief 
 * 
 * @param name 
 * @return std::pair<std::string, std::string> 
 */
std::pair<std::string, std::string> cities::GetAxis(std::string name){
    if(this->cities.count(name)) {
        return this->cities[name];
    }
    return {"0", "0"};
}

/**
 * @brief 
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> cities::GetCities(){
    std::vector<std::string> names;
    for(const auto& city : this->cities) {
        names.push_back(city.first);
    }
    return names;
}