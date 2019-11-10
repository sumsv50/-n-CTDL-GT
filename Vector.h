#pragma once
#include<vector>
using namespace std;
class Vector
{
private:
	vector<float> Data;// Chứa dữ liệu vector
public:
	Vector();//Hàm dựng mặc định
	Vector(int sl);//Hàm dựng 1 tham số. Truyền vào số lượng phần tử vector
	int GetN();
	vector<float> GetVector();
	void Input(int n);
	void Input();
	void Output();
	Vector Cong(Vector v);
	friend void Cong (Vector V1,Vector v2);
	Vector Nhan(int a);
	~Vector();
};

