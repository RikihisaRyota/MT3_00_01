#pragma once

class vector3
{
public:
	float x;
	float y;
	float z;
public:
	vector3();
	vector3(float x, float y, float z);
};

//‰ÁZ
vector3 Add(const vector3& v1, const vector3& v2);
//Œ¸Z
vector3 Subtract(const vector3& v1, const vector3& v2);
//ƒXƒJƒ‰[”{
vector3 Multiply(float scaler, const vector3& v);
//“àÏ
float Dot(const vector3& v1, const vector3& v2);
//’·‚³(ƒmƒ‹ƒ€)
float Length(const vector3& v);
//³‹K‰»
vector3 Normalize(const vector3& v);