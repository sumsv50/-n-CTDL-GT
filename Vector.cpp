#include "Vector.h"
#include<iostream>
using namespace std;

Vector::Vector()
{
}
Vector::Vector(int sl) {
	Data.resize(sl);
}


int Vector::GetN() {
	return Data.size();
}

vector<float> Vector::GetVector() {
	return Data;
}
void Vector::Input(int n) {

	Data.clear();
	Data.resize(n);
	cout << "Nhap Vector:";
	for (int i = 0; i < n; i++)
		cin >> Data[i];
}
void Vector::Input() {
	int n;
	Data.clear();
	cout << "Nhap so luong phan tu vector: ";
	cin >> n;
	Data.resize(n);
	cout << "Nhap Vector:";
	for (int i = 0; i < n; i++) {
		cin >> Data[i];
	}
}
void Vector::Output() {
	for (int i = 0; i < Data.size(); i++) {
		cout << Data[i];
		cout << " ";
	}
	cout << endl;
}
Vector Vector::Cong(Vector v) {
	if (Data.size() != v.Data.size()) cout << "Khong the cong!";
	else {
		Vector tong(Data.size());
		for (int i = 0; i < Data.size(); i++) {
			tong.Data[i] = Data[i] + v.Data[i];
		}
		return tong;
	}
}
void Cong(Vector v1, Vector v2) {
	int n;
	cout << "Nhap so luong phan tu cua 2 vector: ";
	cin >> n;
	cout << "Nhap vector 1" << endl;
	v1.Input(n);
	cout << "Nhap vector 2" << endl;
	v2.Input(n);
	cout << "------->" << endl;
	cout << "v1 + v2 = ";
	Vector v3;
	v3 = v1.Cong(v2);
	v3.Output();
}

Vector Vector::Nhan(int a) {
	int n = Data.size();
	Vector tich(n);
	for (int i = 0; i < n; i++) {
		tich.Data[i] = Data[i] * a;
	}
	return tich;
}

Vector::~Vector()
{
	Data.clear();
}
