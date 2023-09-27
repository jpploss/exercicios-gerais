#include "esfera_utils.h"

void CalculaVolume(float raio, float *volume) {
    *volume = (4.00*PI*raio*raio*raio)/3;
    return;
}

void CalculaArea(float raio, float *area) {
    *area = 4.00*PI*raio*raio;
    return;
}