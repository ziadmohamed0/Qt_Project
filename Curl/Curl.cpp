#include "Curl.h"
#include <sstream>

Curl::Curl(std::string_view latitude, std::string_view longitude, DataAbstract* data_obj)
            : lat(latitude), 
            lon(longitude),
            _data(data_obj)  {
                this->curl = nullptr;
                std::ostringstream ss;
                ss << "https://api.open-meteo.com/v1/forecast?latitude=" << this->lat
                << "&longitude=" << lon << "&hourly=temperature_2m";
                this->url = ss.str();
}

Curl_Status Curl::Curl_init() {
    this->curl = curl_easy_init();
    if(!curl)
        return Curl_Status::FAILED_INIT;
    else
        return Curl_Status::SUCCESS;
}

Curl_Status Curl::Curl_SetUp() {
    if(!this->curl)
        return Curl_Status::FAILED_SETUP;
    curl_easy_setopt(this->curl, CURLOPT_URL, this->url.c_str());
    curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, this->WriteCallback);
    curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, this->_data);
    return Curl_Status::SUCCESS;
} 

Curl_Status Curl::Curl_Perform() {
    if(!this->curl)
        return Curl_Status::FAILED_PERFORM;
    this->result = curl_easy_perform(this->curl);
    if(this->result != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(this->result) << "\n";
        return Curl_Status::FAILED_PERFORM;
    }
    return Curl_Status::SUCCESS;
} 

Curl::~Curl() {
    if(curl) 
        curl_easy_cleanup(this->curl);
} 

size_t Curl::WriteCallback(void* contents, size_t size_, size_t nmemb, void* userp) {
    return static_cast<DataAbstract*>(userp)->write_chunk(contents, size_, nmemb, userp);
}