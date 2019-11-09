#pragma once
#ifndef Bool_h
#define Bool_h
#include<iostream>
#include"stdlib.h"
#include<string>
#include<vector>
using namespace std;
class Tokenizer {
public:
	// Hàm lấy ra các đơn thức
	static vector<string> Parse(string s, string seperator) {
		vector<string> tokens;

		int startpos = 0; // vị trí bắt đầu tìm
		size_t foundpos = s.find(seperator, startpos);

		while (foundpos != string::npos) { // vẫn còn tìm thấy
			int count = foundpos - startpos;
			string token = s.substr(startpos, count);
			tokens.push_back(token);

			//cập nhật vị trí bắt đầu tìm lại
			startpos = foundpos + seperator.length();

			//tiếp tục tìm
			foundpos = s.find(seperator, startpos);
		}

		//phần sót lại chính là phần tử cuối
		int count = s.length() - startpos;
		string token = s.substr(startpos, count);
		tokens.push_back(token);
		return tokens;
	}
};

class Bool {
private:
	vector<vector<int>> Data; // Công thức hàm Bool ban đầu(Dạng nhị phân)
	vector<vector<int>> Datav2; // Lưu các tổ hợp biến/mintern không xác định (Dạng nhị phân)
	vector<vector<int>> cData; // Vùng dữ liệu để lưu trữ các kết quả trong quá trình tính, các tổ hợp biến bắt buộc(Dạng nhị phân)
	vector<vector<vector<int>>> Option; // Vùng dữ liệu lưu trữ các tổ hợp biến không bắt buộc(Dạng nhị phân)

public:
	// Hàm nhập công thức đa thức hàm Bool(Nhập các tổ hợp biến)
	void Inputv1();
	// Hàm nhập công thức đa thức hàm Bool(Nhập các mintern)
	void Inputv2();
	//Hàm xuất ra các công thức đa thức tối tiểu hàm Bool
	void OutMin();
	~Bool();
	//Hàm tìm công thức đa thức tối tiểu và in ra màn hình
	void MinBool();
	//Hàm rút ra các công thức tối tiểu từ các tổ hợp biến không bắt buộc, trả về số công thức đã được rút
	int SetMin(vector<vector<int>>, vector<vector<int>> Data, int& step);//input: Các tổ hợp biến không bắt buộc(Dạng nhị phân) và hệ 10 của nó
	//Hàm chuyển mã nhị phân sang hệ 10
	friend int He10(vector<int>);
	//Hàm kiểm tra xem 2 vector có khác nhau tại 1 phần tử hay không, pos dùng để giữ vị trí khác nhau
	friend bool other1(vector<int>, vector<int>, int& pos);
	//Hàm kiểm tra n có bằng phần tử nào trong vector Data không, pos dùng để giữ vị trí phần tử giống
	friend bool Isrepeat(int n, vector<int> Data, int& pos);
	//Kiểm tra xem các vetor trong vector lớn có bằng nhau hay không, tham số int& dùng để trả về số lượng vector trường hợp đặc biệt
	friend bool Islike(vector<vector<int>>, int&);
	//Kiểm tra xem 2 vector có các phần tử giống nhau hay không(các phần tử giống có thể khác vị trí)
	friend bool Islike(vector<vector<int>>, vector<vector<int>>);
	//Hàm tìm phần tử có số lượng phần tử lớn nhất
	friend vector<int> Posmax(vector<vector<int>>);
	//Hàm xuất các tổ hợp biến;
	friend void OutCom(vector<vector<int>>);
	//Hàm xóa dòng vector, nếu các phần tử cùng bậc có phần tử giống với vector line thì xóa luôn phần tử đó.
	//Trả về vị trí nhưng phần tử vector bị xóa(khi nó rỗng thì xóa)
	friend vector<int> Delline(vector<vector<int>>& v, int line);
	//Hàm tính tổng số vị trí được rút gọn trong vector các tổ hợp biến
	friend int NumShort(vector<vector<int>>);
	////Hàm tính tổng số vị trí được rút gọn của 1 tổ hợp biến
	friend int NumShort(vector<int>);
};
#endif


