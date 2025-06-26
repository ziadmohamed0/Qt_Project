#include  "Rapidjison.h"
        
/**
 * @brief Construct a new Rapidjson:: Rapidjson object
 * 
 * @param Res 
 */
Rapidjson::Rapidjson(char* Res) {
    this->d.Parse(Res);
}

std::string Rapidjson::GetData() {

}

std::string Rapidjson::GetTime() {

}

float Rapidjson::GetTemprature() {

}    

float* Rapidjson::GetMinForeCastTemp() {

}  

float* Rapidjson::GetMaxForeCastTemp() {

}   

std::string* Rapidjson::GetForeCastTemp() {

}

/**
 * @brief Destroy the Rapidjson:: Rapidjson object
 * 
 */
Rapidjson::~Rapidjson() {

}