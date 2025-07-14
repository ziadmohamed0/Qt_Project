#ifndef CITIES_H_
#define CITIES_H_

#include <map>
#include <string>
#include <vector>

class Cities {
    public:
        void AddCity(std::string name, std::string laitude, std::string longitude);
        std::pair<std::string, std::string> GetAxis(std::string name);
        std::vector<std::string> GetCities();
    private:
        std::map<std::string, std::pair<std::string, std::string> > cities;
};

#endif