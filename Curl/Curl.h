#ifndef CURL_H_
#define CURL_H_

#include "../CurlAbstract/CurlAbstract.h"
#include "../DataAbstract/DataAbstract.h"

class Curl : public CurlAbstract {
    public:
        Curl(std::string latitiude, std::string longtiude, DataAbstract *DataAbstract);
        Curl();
        Curl_Status Curl_init() override;
        Curl_Status Curl_Setup() override;
        Curl_Status Curl_Perform() override;
        ~Curl();
    private:
};

#endif