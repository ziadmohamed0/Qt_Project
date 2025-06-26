/**
 * @file DataAbstract.h
 * @author Ziad Mohammed Fathy
 * @brief Data Abstract header file
 * @version 0.1
 * @date 2025-06-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DATA_ABSTRACT_H_
#define DATA_ABSTRACT_H_

#include <iostream>

class DataAbstract {        
    public:
        virtual char *GetResponse() = 0;
        virtual ~DataAbstract() {}
    protected: 
        char* Response;
        size_t size;
};


#endif