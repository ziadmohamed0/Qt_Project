#ifndef CURL_H_
#define CURL_H_

#include "../CurlAbstract/CurlAbstract.h"
#include "../Data/Data.h"

class Curl : public CurlAbstract {
    public:
        Curl(std::string_view latitude, std::string_view longitude, DataAbstract* data_obj);
        Curl_Status Curl_init() override; 
        Curl_Status Curl_SetUp() override;
        Curl_Status Curl_Perform() override; 
        ~Curl();
    private:
        std::string lat, lon, url;
        DataAbstract* _data;
        static size_t WriteCallback(void* contents, size_t size_, size_t nmemb, void* userp);
};

#endif