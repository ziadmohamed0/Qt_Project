#ifndef RAPID_JSON_ABSTRACT_H_
#define RAPID_JSON_ABSTRACT_H_

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <iostream>
#include "../Data/Data.h"

class RapidjsonAbstract {
    public:
        RapidjsonAbstract();
        virtual std::string GetDate() = 0;
        virtual std::string GetTime() = 0;
        virtual float GetTemprature() = 0;
        virtual ~RapidjsonAbstract() = 0;
    protected:
        rapidjson::Document d;
};

#endif