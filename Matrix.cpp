#include"Matrix.h"
Matrix::Matrix()
{
	column = line = 0;
	Data = NULL;
}
Matrix::Matrix(int n, int m) {
	line = n;
	column = m;
	Data = new float*[n];
	for (int i = 0; i < n; i++)
		Data[i] = new float[m];
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
			Data[i][j] = 0;
}
Matrix::Matrix(const Matrix& other) {
	column = other.column;
	line = other.line;
	Data = new float*[line];
	for (int i = 0; i < line; i++)
		Data[i] = new float[column];
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
			Data[i][j] = other.Data[i][j];
}
void Matrix::Input() {
	for (int i = 0; i < line; i++)
		delete[] Data[i];
	delete[] Data;
	cout << "Nhap so dong: ";
	cin >> line;
	cout << "Nhap so cot: ";
	cin >> column;
	Data = new float*[line];
	for (int i = 0; i < line; i++)
		Data[i] = new float[column];
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
		{
			cout << "Nhap pt[" << i + 1 << "]" << "[" << j + 1 << "]: ";
			cin >> Data[i][j];
		}
}
void Matrix::Inputv()
{
	for (int i = 0; i < line; i++)
		delete[] Data[i];
	delete[] Data;
	cout << "Nhap so dong(cot): ";
	cin >> line;
	column = line;
	Data = new float* [line];
	for (int i = 0; i < line; i++)
		Data[i] = new float[column];
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
		{
			cout << "Nhap pt[" << i + 1 << "]" << "[" << j + 1 << "]: ";
			cin >> Data[i][j];
		}
}
void Matrix::Output() {
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
			if(Data[i][j]>=0)
			cout << " " << Data[i][j] << "\t";
			else cout << Data[i][j] << "\t";
		cout << endl;
	}
}
Matrix& Matrix::operator=(const Matrix& src)
{
	if (this != &src) {
		for (int i = 0; i < line; i++)
			delete[] Data[i];
		line = src.line;
		column = src.column;
		Data = new float* [line];
		for (int i = 0; i < line; i++)
			Data[i] = new float[column];
		for (int i = 0; i < line; i++)
			for (int j = 0; j < column; j++)
				Data[i][j] = src.Data[i][j];
	}
	return *this;
}
int Matrix::getline() {
	return line;
}

Matrix Matrix::compMatrix(int l, int c)
{
	Matrix A(line - 1, column - 1);
	//Hai biến A.line và A.column dùng để giữ địa chỉ phần tử của ma trận A
	//Hai biến i,j để giữ địa chỉ phần tử ma trận this
	for (int i = 0, Aline = 0; i < line; i++)
	{
		//Không sao chép dòng l(line) của ma trận this
		if (i == l) continue;
		for (int j = 0, Acolumn = 0; j < column; j++)
		{
			//Không sao chép cột c(column) của ma trận this
			if (j == c) continue;
			A.Data[Aline][Acolumn] = Data[i][j];
			Acolumn++;
		}
		Aline++;
	}
	return A;
}

float Matrix::Determinant() {
	if (line != column) throw;//Nếu ma trận không vuông thì báo lỗi
	//Tính Det theo công thức đã học
	if (line == 1) return Data[0][0];
	if (line == 2) return Data[0][0] * Data[1][1] - Data[1][0] * Data[0][1];
	float Det = 0;
	//Mij=(-1)^(i+j) * Det(A(i|j))
	//Det=a00*M00+a10*M10+...+an0*Mn0
	for (int i = 0; i < line; i++) Det += pow(-1,i)*Data[i][0] * this->compMatrix(i, 0).Determinant();
	return Det;
};

Matrix Matrix::inverseMatrix()
{
	Matrix ivA(line, column);
	if (line != column) throw;//Nếu ma trận không vuông thì báo lỗi
	int Det = this->Determinant();//Tính định thức ma trận
	if (Det == 0)//Nếu ma trận không khả nghịch thì báo lỗi
		ivA.line = ivA.column = 0;
	
	//adj(A) = M^T(Ma trận chuyển vị của M)
	//A^(-1) = (1/Det(A)) * adj(A)
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
			ivA.Data[j][i] = pow(-1, i + j)*this->compMatrix(i, j).Determinant()/Det;
	return ivA;
}

Matrix Matrix::Multiply(const Matrix &src) {
	Matrix Temp(line, src.column);//Tạo ma trận mới(là ma trận tích)
	if (column != src.line)//Nếu số cột của ma trận trước khác số dòng của ma trận sau thì báo lỗi
		Temp.line = Temp.column = 0;
	//Tính ma trận tích
	for(int i = 0; i < Temp.line; i++)
		for (int j = 0; j < Temp.column; j++)
		{
			//Phần tử (i,j) của A.B là tích vô hướng của vector dòng i của A và vector cột j của B
			for (int k = 0; k < column; k++)
				Temp.Data[i][j] += Data[i][k] * src.Data[k][j];
		}
	return Temp;
}
void Matrix::swapLine(int i1, int i2)
{
	int temp;
	//Hoán đổi từng phần tử 2 hàng cho nhau.
	for (int cout = 0; cout < column; cout++)
	{
		temp = Data[i1][cout];
		Data[i1][cout] = Data[i2][cout];
		Data[i2][cout] = temp;
	}
}
void Matrix::Degree()
{
	for (int i = 0, j = 0; i < line && j < column; j++, i++)//Giới hạn phạm vi làm việc là các phần tử trong mảng
	{
		//Nếu phần tử tại vị trí ta đang xét bằng 0 thì ta tìm xem dưới nó(cùng cột) có phần tử nào khác O không
		//Nếu có thì ta hoán đổi 2 hàng chứa phần tử ta đang xét và phần tử đó
		if (Data[i][j] == 0)
			for (int k = i + 1; k < line; k++)
			{
				if (Data[k][j] != 0)
				{
					swapLine(i, k);
					break;
				}
			}
		//Nếu phần tử ta đang xét vẫn bằng 0 thì chứng tỏ các số dưới nó(cùng cột) đều bằng 0
		//lúc này ta không cần làm gì, chỉ cần nhảy đến phần tử bên phải nó(cùng hàng) và lại xét phần tử này
		//Ngược lại nếu phần tử ta đang xét khác 0 thì ta cần phải đưa các phần tử dưới nó về 0(dạng bậc thang)
		//bằng cách biến đổi sơ cấp dòng
		//Khi các biến ra ngoài phạm vi ma trận thì ma trận đã được đưa về dạng bậc thang
		if (Data[i][j] != 0)
		{
			//Biến đổi sơ cấp các dòng
			for (int i2 = i + 1; i2 < line; i2++)
			{
				if (Data[i2][j] != 0)
				{
					float PS = -Data[i2][j] / Data[i][j];
					for (int j2 = j; j2 < column; j2++)
						Data[i2][j2] += PS * Data[i][j2];
				}
			}
		}
		else i--;
	}
}
int Matrix::Rank()
{
	int rank = 0;
	Matrix Temp(*this);
	//Đưa Temp về dạng ma trận bậc thang
	Temp.Degree();
	//Đếm số dòng khác 0 của ma trận bậc thang(chính là hạng của ma trận cần tìm)
	for (int i = 0, j = 0; i < line; i++)
	{
		for(;j < column; j++)//Đặt phạm vi là các phần tử trong ma trận
		{
			if (Temp.Data[i][j] != 0)//Nếu dòng đó có phần tử khác 0 thì tăng rank lên 1 và xét hàng dưới nó
			{
				rank++;
				j++;
				break;
			}
		}
		if (j >= column) return rank;
		//Vì phía trên có lệnh break nên nếu j>=column thì các phần tử hàng đó đều bằng 0 hoặc phần tử trụ đã ở cột cuối cùng
		//Lúc này ta return rank vì các dòng bên dưới dòng này(nếu có) chắc chắc sẽ là dòng 0(vì là dạng bậc thang)

	}
	//Nếu đã vượt qua phạm vi ma trận thì ta return rank
	return rank;
}
void Matrix::solveLinearSystem()
{
	cout << "Nhap ma tran he so"<<endl;
	Matrix A;
	A.Input();
	cout << "Nhap cot he so tu do" << endl;
	vector<float> B;//Cột hệ số tự do.
	B.resize(A.line);
	for (int i = 0; i < B.size(); i++)
	{
		cout << "Nhap B[" << i + 1 << "]:";
		cin >> B[i];
	}
	Matrix Amr(A.line, A.column + 1);//Ma trận mở rộng, lớn hơn ma trận A một cột
	//Gán dữ liệu cho ma trận mở rộng
	for (int i = 0; i < A.line; i++)//copy dữ liệu từ ma trận A sang ma trận mở rộng(để trống cột cuối cùng Amr)
		for (int j = 0; j < A.column; j++)
			Amr.Data[i][j] = A.Data[i][j];
	for (int i = 0; i < Amr.line; i++)//copy dữ liệu cột hệ số tự do sang ma trận mở rộng(Tại cột cuối cùng Amr)
		Amr.Data[i][A.column] = B[i];
	int rA = A.Rank();
	int rAmr = Amr.Rank();
	if (rA != rAmr) cout << "He vo nghiem.";
	else
	{
		if (rA < A.column) cout << "He co vo so nghiem phu thuoc " << A.column - rA << " tham so.";
		else
		{
			Amr.Degree();
			vector<float> Result;
			Result.resize(A.line);
			for (int i = A.line - 1, j = A.column - 1; i >= 0; i--, j--)
			{
				Result[j]=Amr.Data[i][Amr.column - 1] ;
				for (int j2 = j + 1; j2 < A.column; j2++)
					Result[j] -= Amr.Data[i][j2]*Result[j2];
				Result[j] /= Amr.Data[i][j];
			}
			cout << "Nghiem cua he: "<<endl;
			for (int i = 0; i < Result.size(); i++)
				cout << "x" << i + 1 << " = " << Result[i] << endl;
		}
	}
}

Matrix::~Matrix() {
	column = line = 0;
	//Xóa vùng dữ liệu đã được cấp phát
	for (int i = 0; i < line; i++)
		delete[] Data[i];
	delete[] Data;

}
