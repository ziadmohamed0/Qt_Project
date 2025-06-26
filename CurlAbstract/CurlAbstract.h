/**
 * @file CurlAbstract.h
 * @author Ziad Mohammed Fathy
 * @brief Curl Abstract header file.
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CURL_ABSTRACT_H_
#define CURL_ABSTRACT_H_

#include <curl/curl.h>

enum class Curl_Status {
    SUCCESS,
    FAILED_INIT,
    FAILED_SETUP,
    FAILED_PERFORM
};

class CurlAbstract {
    public:
        virtual Curl_Status Curl_init() = 0;
        virtual Curl_Status Curl_Setup() = 0;
        virtual Curl_Status Curl_Perform() = 0;
        CurlAbstract();

    protected:
        CURL *curl;
        CURLcode resulte;
        char* weatherAPI;
};

#endif