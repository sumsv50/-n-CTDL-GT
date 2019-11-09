#include"Console.h"
#include"Vector.h"
#include"Matrix.h"
#include"Bool.h"
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	Vector v1, v2, v3;
	Matrix A, B, C;
	Bool F;
	int m, n, a;
	Name1();
	Sleep(900);
	do {
		system("cls");
		GotoXY(10,0);
		TextColor(3);
		cout << "UNG DUNG HO TRO HOC TOAN" << endl;
		TextColor(7);
		cout << "Cac chuc nang:" << endl;
		cout << "1. Cong thuc da thuc toi tieu ham Bool" << endl;
		cout << "2. Phep toan tren vector" << endl;
		cout << "3. Phep toan tren ma tran" << endl;
		cout << "0. Thoat" << endl;
		cout << "=====================================" << endl;
		TextColor(8);
		cout << "Nhap chuc nang: ";
		TextColor(7);
		cin >> m;
		switch (m) {
		case 1:
			system("cls");
			TextColor(2);
			cout <<endl<< " TIM CONG THUC DA THUC TOI TIEU HAM BOOL";
			TextColor(7);
			cout << endl << "Nhap ham Bool: " << endl;
			cout << " 1. Nhap bang cac to hop bien" << endl;
			cout << " 2. Nhap bang cac mintern" << endl;
			cout << "0. Back" << endl;
			cout << "=====================================" << endl;
			do {
				
				TextColor(8);
				Sleep(500);
				cout << "Nhap chuc nang:  ";
				TextColor(7);
				cin >> n;
				switch (n)
				{
				case 1:
					F.Inputv1();
					F.MinBool();
					cout << "------->" << endl;
					F.OutMin();
					cout << endl;
					break;
				case 2:
					F.Inputv2();
					F.MinBool();
					cout << "------->" << endl;
					F.OutMin();
					cout << endl;
					break;
				case 0:
					break;
				default:
					cout << "Khong hop le!"<<endl;
					cout << endl;
					break;
				}
			} while (n != 0);
			break;
		case 2:
			system("cls");
			TextColor(6);
			cout <<endl<<"\t"<< "PHEP TOAN TREN VECTOR" << endl;
			TextColor(7);
			cout << "1. Cong 2 vector" << endl;
			cout << "2. Nhan vector voi 1 so alpha" << endl;
			cout << "0. Back" << endl;
			cout << "=====================================" << endl;
			do {
				TextColor(8);
				Sleep(500);
				cout << endl << "Nhap chuc nang: ";
				TextColor(7);
				cin >> n;
				switch (n)
				{
				case 1:
					Cong(v1, v2);
					break;
				case 2:
					v1.Input();
					cout << "Nhap so alpha: ";
					cin >> a;
					v2 = v1.Nhan(a);
					cout << "------->" << endl;
					cout << "KQ: ";
					v2.Output();
					break;
				case 0:
					break;
				default:
					cout << "Khong hop le!"<<endl;
					break;
				};
			} while (n != 0);
			break;
		case 3:
			system("cls");
			TextColor(10);
			cout << endl << "\t" << "PHEP TOAN TREN MA TRAN" << endl;
			TextColor(7);
			cout << "1. Tim dinh thuc ma tran" << endl;
			cout << "2. Tim nghich dao ma tran" << endl;
			cout << "3. Tich 2 ma tran" << endl;
			cout << "4. Hang cua ma tran" << endl;
			cout << "5. He phuong trinh tuyen tinh" << endl;
			cout << "0. Back" << endl;
			cout << "=====================================" << endl;
			do {
				TextColor(8);
				Sleep(500);
				cout << endl << "Nhap chuc nang: ";
				TextColor(7);
				cin >> n;
				switch (n)
				{
				case 1:
					A.Inputv();
					cout << "------->" << endl;
					cout << "Det = " << A.Determinant() << endl;
					break;
				case 2:
					A.Inputv();
					B = A.inverseMatrix();
					cout << "------->" << endl;
					if (B.getline() == 0) cout << "Ma tran khong kha nghich! Khong co nghich dao.";
					else {
						cout << "Ma tran nghich dao: " << endl;
						B.Output();
					}
					break;
				case 3:
					cout << "Nhap ma tran thu nhat" << endl;
					A.Input();
					cout << "Nhap ma tran thu hai" << endl;
					B.Input();
					C = A.Multiply(B);
					cout << "------->" << endl;
					if (C.getline() == 0) cout << "Khong the nhan 2 ma tran!";
					else {
						cout << "Ma tran tich" << endl;
						C.Output();
					}
					break;
				case 4:
					A.Input();
					cout << "------->" << endl;
					cout << "Hang cua ma tran: r = " << A.Rank();
					break;
				case 5:
					A.solveLinearSystem();
					break;
				default:
					cout << "Khong hop le!"<<endl;
					break;
				};
			} while (n != 0);
			break;
		case 0:
			break;
		default:
			cout << "Khong hop le!";
			break;
		}
	} while (m != 0);
	system("cls");
	Name2();
	Sleep(1000);

}
