#include "vector3.h"
#include <cmath>
vector3::vector3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

vector3::vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vector3 Add(const vector3& v1, const vector3& v2)
{
    vector3 tmp;
    tmp.x = v1.x + v2.x;
    tmp.y = v1.y + v2.y;
    tmp.z = v1.z + v2.z;
    return tmp;
}

vector3 Subtract(const vector3& v1, const vector3& v2)
{
    vector3 tmp;
    tmp.x = v1.x - v2.x;
    tmp.y = v1.y - v2.y;
    tmp.z = v1.z - v2.z;
    return tmp;
}

vector3 Multiply(float scaler, const vector3& v)
{
    vector3 tmp;
    tmp.x = v.x * scaler;
    tmp.y = v.y * scaler;
    tmp.z = v.z * scaler;
    return tmp;
}

float Dot(const vector3& v1, const vector3& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Length(const vector3& v)
{
    return std::sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

vector3 Normalize(const vector3& v)
{
    vector3 tmp;
    float length = Length(v);
    tmp.x = v.x / length;
    tmp.y = v.y / length;
    tmp.z = v.z / length;
    return tmp;
}
