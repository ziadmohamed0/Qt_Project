#ifndef RAPIDJSON_H_
#define RAPIDJSON_H_

#include "../RapidjsonAbstract/RapidjsonAbstract.h"

class Rapidjson : public RapidjsonAbstract {
    public:
        Rapidjson(char* Res);
        virtual std::string GetData() override;
        virtual std::string GetTime() override;
        virtual float GetTemprature() override;    
        float* GetMinForeCastTemp();    
        float* GetMaxForeCastTemp();    
        std::string* GetForeCastTemp();
        ~Rapidjson();
};


#endif