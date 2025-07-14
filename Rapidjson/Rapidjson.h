#ifndef RAPID_JSON_H_
#define RAPID_JSON_H_

#include "../RapidjsonAbstract/RapidjsonAbstract.h"

class Rapidjson : public RapidjsonAbstract {
    public:
        Rapidjson(const std::string& Res);
        std::string GetDate() override;
        std::string GetTime() override;
        float GetTemprature() override;
        float* GetMiniForCastTemp();
        float* GetMaxForCastTemp();
        std::string* GetForCastDaate();
        ~Rapidjson();
    private:
        float* minTemps = nullptr;
        float* maxTemps = nullptr;
        std::string* forecastDates = nullptr;
        int forecastSize = 0;
};

#endif