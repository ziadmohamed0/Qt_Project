/**
 * @file Data.cpp
 * @author Ziad Mohammed Fathy
 * @brief Data defination file
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Data.h"

Data::Data() {
    this->Response = nullptr;
}

char *Data::GetResponse() {
    return this->Response;
}

size_t Data::write_chunk(void* contents, size_t size_, size_t nmemb, void* userp) {
    size_t totalSize = (size_ * nmemb);
    Data* self = static_cast<Data*>(userp);

    char* new_response = new char[self->size + totalSize + 1];

    if(self->Response != nullptr) {
        std::memcpy(new_response, self->Response, self->size);
        delete[] self->Response;
    }

    std::memcpy(new_response + self->size, contents, totalSize);
    new_response[self->size + totalSize] = '\0';

    self->Response = new_response;
    self->size += totalSize;

    return totalSize;
}

Data::~Data() {
    if(this->Response != nullptr) {
        delete[] this->Response;
        this->Response = nullptr;
    }
}