#ifndef DATA_H_
#define DATA_H_

#include "../DataAbstract/DataAbstract.h"

class Data : public  DataAbstract{
    public:
        Data();
        size_t write_chunk(void* data, size_t size_, size_t nmemb, void* userdata);
        std::string GetResponse() const override;
        ~Data();
    private:
        std::string buffer;
};

#endif