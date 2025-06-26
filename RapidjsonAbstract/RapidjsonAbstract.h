/**
 * @file RapidjsonAbstract.h
 * @author Ziad Mohammed Fathy
 * @brief RapidJason Abstract header file
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef RAPID_JSON_ABSTRACT_H_
#define RAPID_JSON_ABSTRACT_H_

#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>


class RapidjsonAbstract {
    public:
        virtual std::string GetData() = 0;
        virtual std::string GetTime() = 0;
        virtual float GetTemprature() = 0;
        virtual ~RapidjsonAbstract() {}
    protected:
        rapidjson::Document d;
};

#endif
