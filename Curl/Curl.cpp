#include "Curl.h"
#include <sstream>

Curl::Curl(std::string latitiude, std::string longtiude, DataAbstract *DataAbstract)  :
            lat(latitiude),
            lon(longtiude),
            DA(DataAbstract) {
    this->curl = nullptr;
    std::ostringstream ss;
    ss << "https://api.open-meteo.com/v1/forecast?latitude=" << this->lat
    << "&longitude=" << this->lon << "&hourly=temperature_2m";   
    this->url = ss.str(); 
}

Curl_Status Curl::Curl_init() {
    this->curl = curl_easy_init();
    if(!this->curl)
        return Curl_Status::FAILED_INIT;
    else 
       return Curl_Status::SUCCESS;
}

Curl_Status Curl::Curl_Setup() {
    if (!curl) return Curl_Status::FAILED_INIT;

    if (curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str()) != CURLE_OK)
        return Curl_Status::FAILED_SETUP;

    if (curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_chunk) != CURLE_OK)
        return Curl_Status::FAILED_SETUP;

    if (curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, this->DA) != CURLE_OK)
        return Curl_Status::FAILED_SETUP;

    return Curl_Status::SUCCESS;
}

Curl_Status Curl::Curl_Perform() {
    return Curl_Status::SUCCESS;

}

Curl::~Curl() {

}
