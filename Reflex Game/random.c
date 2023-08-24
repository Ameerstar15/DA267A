
#include "random.h"
#include "esp_random.h"

int getRandommsecs(int min, int max)
{

    uint32_t R =  esp_random();
    float rr = (R / UINT32_MAX);
    return min + rr * (max - min); 
}