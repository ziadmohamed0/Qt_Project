#ifndef CURL_ABSTRACT_H_
#define CURL_ABSTRACT_H_

#include <iostream>
#include <curl/curl.h>
#include <string>
#include "../DataAbstract/DataAbstract.h"

enum class Curl_Status {
    SUCCESS,
    FAILED_INIT,
    FAILED_SETUP,
    FAILED_PERFORM
};

class CurlAbstract {
    public:
        CurlAbstract() = default;
        virtual Curl_Status Curl_init() = 0; 
        virtual Curl_Status Curl_SetUp() = 0;
        virtual Curl_Status Curl_Perform() = 0; 
    protected:
        CURL* curl;
        CURLcode result;
        char* WeatherAPI;
};

#endif