#ifndef DATA_ABSTRACT_H_
#define DATA_ABSTRACT_H_

#include <iostream>

class DataAbstract {
    public: 
        DataAbstract() = default;
        virtual std::string GetResponse() const = 0;
        virtual size_t write_chunk(void* contents, size_t size_, size_t nmemb, void* userp) = 0;
        ~DataAbstract();
    protected:
        char* Response;
        size_t size;
};

#endif