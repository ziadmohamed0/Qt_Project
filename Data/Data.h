/**
 * @file Data.h
 * @author Ziad Mohammed Fathy
 * @brief Data header file
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DATA_H_
#define DATA_H_

#include "../DataAbstract/DataAbstract.h"
#include <cstring>


class Data : public DataAbstract {
    public: 
        Data();
        char *GetResponse() override;
        size_t write_chunk(void* contents, size_t size_, size_t nmemb, void* userp);
        ~Data();
};

#endif