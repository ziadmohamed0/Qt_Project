#include "Data.h"

Data::Data() {
    this->Response = nullptr;
}

size_t Data::write_chunk(void* data, size_t size_, size_t nmemb, void* userdata) {
    const size_t total_size_buffer = size_ * nmemb;
    this->buffer.append(static_cast<char*>(data), total_size_buffer);
    return total_size_buffer;
}

std::string Data::GetResponse() const{
    return this->buffer;
}

Data::~Data() = default;
DataAbstract::~DataAbstract() = default;
