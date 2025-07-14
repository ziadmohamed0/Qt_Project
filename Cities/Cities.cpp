#include "Cities.h"

void Cities::AddCity(std::string name, std::string laitude, std::string longitude) {
    this->cities[std::string(name)] = {std::string(laitude), std::string(longitude)};
}

std::pair<std::string, std::string> Cities::GetAxis(std::string name) {
    return this->cities.at(name);
}

std::vector<std::string> Cities::GetCities() {
    std::vector<std::string> keys;
    for (const auto& [name, _] : this->cities)
        keys.push_back(name);
    return keys;
}