// NAMA       : Muhammad Haekal Muhyidin Al-Araby
// NRP        : 5024221030
// Jurusan    : Teknik Komputer

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan
#define PI 3.14159265


float mencari_V0(float v, float loss)
{
    return v - loss;
}

float speed_dgn_loss(float v)
{
    int loss;
    if (v >= 1 && v <= 10) loss = 1;
    else if (v >= 11 && v <= 20) loss = 3;
    else if (v >= 21 && v <= 30) loss = 5;

    v = mencari_V0(v, loss);

    return v;
}

int jarak_max(float v)
{
    int x;
    x = v * v * sin(2 * SUDUT * PI/180) / GRAVITASI;
    return x;
}

float v_Tangensial(int x)
{
    float v = sqrt(x * GRAVITASI / sin(2 * SUDUT * PI/180));
    if (v >= 1 && v <= 10) v += 1;
    else if (v >= 11 && v <= 20) v += 3;
    else if (v >= 21 && v <= 30) v += 5;
    return v;
}

int main()
{
    float v;
    std::cin >> v;

    v = speed_dgn_loss(v);

    int jarak = jarak_max(v);

    float vTangensial = v_Tangensial(jarak);

    std::cout << jarak << " " << vTangensial << std::endl;
    return 0;
}
