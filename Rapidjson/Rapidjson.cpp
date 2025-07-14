#include "Rapidjson.h"

Rapidjson::Rapidjson(const std::string& Res) {
    this->d.Parse(Res.c_str());

    if (this->d.HasMember("daily")) {
        const auto& daily = this->d["daily"];

        if (daily.HasMember("temperature_2m_min") && daily["temperature_2m_min"].IsArray() &&
            daily.HasMember("temperature_2m_max") && daily["temperature_2m_max"].IsArray() &&
            daily.HasMember("time") && daily["time"].IsArray()) {

            this->forecastSize = daily["temperature_2m_min"].Size();

            this->minTemps = new float[this->forecastSize];
            this->maxTemps = new float[this->forecastSize];
            this->forecastDates = new std::string[this->forecastSize];

            for (int i = 0; i < this->forecastSize; ++i) {
                this->minTemps[i] = daily["temperature_2m_min"][i].GetFloat();
                this->maxTemps[i] = daily["temperature_2m_max"][i].GetFloat();
                this->forecastDates[i] = daily["time"][i].GetString();
            }
        }
    }
}

std::string Rapidjson::GetDate() {
    if (d.HasMember("hourly") && d["hourly"].HasMember("time") && d["hourly"]["time"].IsArray())
        return d["hourly"]["time"][0].GetString();
    return "";
}

std::string Rapidjson::GetTime() {
    if (d.HasMember("hourly") && d["hourly"].HasMember("time") && d["hourly"]["time"].IsArray())
        return d["hourly"]["time"][0].GetString();
    return "";
}

float Rapidjson::GetTemprature(){
    if (d.HasMember("hourly") && d["hourly"].HasMember("temperature_2m") && d["hourly"]["temperature_2m"].IsArray())
        return d["hourly"]["temperature_2m"][0].GetFloat();
    return -999.0f;
}

float* Rapidjson::GetMiniForCastTemp() {
    return this->minTemps;    
}

float* Rapidjson::GetMaxForCastTemp(){
    return this->maxTemps;
}

std::string* Rapidjson::GetForCastDaate() {
    return this->forecastDates;
}

Rapidjson::~Rapidjson() {
    delete[] minTemps;
    delete[] maxTemps;
    delete[] forecastDates;
}

RapidjsonAbstract::~RapidjsonAbstract() = default;
RapidjsonAbstract::RapidjsonAbstract() = default;