/**
 * @file cities.h
 * @author Ziad Mohammed Fathy
 * @brief Cities header file.
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CITIES_H_
#define CITIES_H_

#include <iostream>
#include <map>
#include <vector>

class cities {
    public:
        void AddCity(std::string name, std::string latitiude, std::string longtiude);
        std::pair<std::string, std::string> GetAxis(std::string name);
        std::vector<std::string> GetCities();
    private:
        std::map<std::string, std::pair<std::string, std::string>> cities;
};


#endif