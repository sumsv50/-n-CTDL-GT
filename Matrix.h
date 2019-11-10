#pragma once
#ifndef Matrix_h
#define Matrix_h
#include"math.h"
#include<vector>
#include<iostream>
using namespace std;
class Matrix {
private:
	int column, line;
	float** Data;
public:
	//Hàm dựng mặc định
	Matrix();
	//Hàm dựng sao chép
	Matrix(const Matrix& other);
	//Hàm dựng 2 tham số
	Matrix(int, int);
	//Hàm nhập ma trận
	void Input();
	//Hàm nhập ma trận vuông
	void Inputv();
	//Hàm xuất ma trận
	void Output();
	int getline();
	//Hàm tìm định thức ma trận
	float Determinant();
	//Hàm tạo ma trận mới bằng cách sao chép ma trận gọi hàm, trừ dòng l và cột c
	Matrix compMatrix(int l, int c);
	//Hàm tìm ma trận nghịch đảo, trả về ma trận nghịch đảo đó
	Matrix inverseMatrix();
	//Hàm nhân 2 ma trận. Truyền vào một ma trận, trả về ma trận tích
	Matrix Multiply(const Matrix& src);
	//Hàm hoán đổi 2 dòng của ma trận.
	void swapLine(int i1, int i2);
	//Đưa ma trận gọi hàm về ma trận bậc thang. Không tham số và giá trị trả về
	void Degree();
	//Hàm tính hạng ma trận, trả về 1 số kiểu nguyên
	int Rank();
	//Hàm giải phương trình tuyến tính
	//Matrix gọi hàm: ma trận hệ số
	//Matrix B truyền vào: cột hệ số tự do
	void solveLinearSystem();
	//Hàm hủy
	~Matrix();
	Matrix& operator=(const Matrix& src);
};
#endif
