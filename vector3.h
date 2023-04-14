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

//���Z
vector3 Add(const vector3& v1, const vector3& v2);
//���Z
vector3 Subtract(const vector3& v1, const vector3& v2);
//�X�J���[�{
vector3 Multiply(float scaler, const vector3& v);
//����
float Dot(const vector3& v1, const vector3& v2);
//����(�m����)
float Length(const vector3& v);
//���K��
vector3 Normalize(const vector3& v);