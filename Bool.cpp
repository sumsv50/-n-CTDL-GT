#include"Bool.h"
using namespace std;

void Bool::Inputv1()
{
	Data.clear(); Datav2.clear(); cData.clear(); Option.clear();//Xóa các dữ liệu trước đó
	string s;
	int nbien; // Lưu số lượng  biến
	
	vector<int> temp;
	string seperator = " + "; //kí tự phân cách
	cout << "Nhap so luong bien: ";
	cin >> nbien;
	cout << "Nhap ham bool:";
	cout << "F(";
	for (int i = 0; i < nbien-1; i++)
		cout << static_cast<char>(65 + i) << ", ";
	cout << static_cast<char>(65 + nbien - 1) << "): ";
	rewind(stdin);
	getline(cin, s);
	vector<string> tokens = Tokenizer::Parse(s, seperator);//Lấy ra các đơn thức
	//Chuyển về dạng mã nhị phân của nó, chuyển từng  tổ hợp biến
	for (int i = 0; i < tokens.size(); i++)
	{
		for (int j = 0; j < nbien; j++)
			temp.push_back(-1);
		Data.push_back(temp);//Gán các phần tử bằng -1 để đánh dấu là chưa được set giá trị.
		temp.clear();

		//Thêm khoảng trống vào cuối các đơn thức để có thể đọc dấu ' dễ dàng hơn
		tokens[i].push_back(' ');
	
		const char* s = tokens[i].c_str();//Chuyển string về dạng char để chuyển qua số nguyên nhằm xác định vị trí
		for (int j = 0; j < tokens[i].size() && tokens[i][j] != ' '; j++)//Chạy đến hết tổ hợp
		{

			int vt = s[j] - 65;//VD: A có số thứ tự trong bang ma ASCII là 65. 65-65=0. A ở vị trí đầu tiên trong tổ hợp 
			if (tokens[i][j + 1] == '\'')
			{
				Data.at(i).at(vt) = 0;
				j++;
			}
			else Data.at(i).at(vt) = 1;
		}
	}
	int Nminterm = tokens.size();
	//Set giá trị cho nhưng thành phần trong tổ hợp biến chưa được set giá trị, nhân đôi và thế vào 0 và 1
	for (int i = 0; i < Nminterm; i++)
		for (int j = 0; j < nbien; j++) {
			if (Data.at(i).at(j) == -1)
			{
				Data.at(i).at(j) = 0; //Gán bằng 0
				for (int count = 0; count < nbien; count++)//Nhân đôi
					temp.push_back(Data.at(i).at(count));
				temp[j] = 1;//Tại vị trí gán bằng 0 giờ gán bằng 1
				Data.push_back(temp);
				Nminterm++;//Tăng số mintorn lên 1 đơn vị
				temp.clear();
			}
		}
	//Tương tự như trên
	cout << "Nhap cac to hop bien khong xac dinh: ";
	getline(cin, s);
	if (s != "") {
		temp.clear();
		vector<string> tokens = Tokenizer::Parse(s, seperator);
		for (int i = 0; i < tokens.size(); i++)
		{
			for (int j = 0; j < nbien; j++)
				temp.push_back(-1);
			Datav2.push_back(temp);
			temp.clear();

			//Thêm khoảng trống vào cuối các đơn thức để có thể đọc dấu ' dễ dàng hơn
			tokens[i].push_back(' ');
			/*char* c = new char[tokens[i].size()+1];
			copy(tokens.begin(), tokens.end(), c);
			c[s.size()] = '\0';*/
			const char* s = tokens[i].c_str();
			for (int j = 0; j < tokens[i].size() && tokens[i][j] != ' '; j++)
			{

				int vt = s[j] - 65;
				if (tokens[i][j + 1] == '\'')
				{
					Datav2.at(i).at(vt) = 0;
					j++;
				}
				else Datav2.at(i).at(vt) = 1;
			}
		}
		int Nminterm = tokens.size();
		for (int i = 0; i < Nminterm; i++)
			for (int j = 0; j < nbien; j++) {
				if (Datav2.at(i).at(j) == -1)
				{
					Datav2.at(i).at(j) = 0;
					for (int count = 0; count < nbien; count++)
						temp.push_back(Datav2.at(i).at(count));
					temp[j] = 1;
					Datav2.push_back(temp);
					Nminterm++;
					temp.clear();
				}
			}
	}
}
//Nhập hàm bool bằng các mintern
void Bool::Inputv2()
{
	Data.clear(); Datav2.clear(); cData.clear(); Option.clear();
	string s;
	int nbien; // Lưu số lượng  biến
	int temp;
	int count;
	vector<int> mintern;
	string seperator = " "; //kí tự phân cách
	cout << "Nhap so luong bien: ";
	cin >> nbien;
	mintern.resize(nbien);
	cout << "Nhap ham bool:";
	cout << "F(";
	for (int i = 0; i < nbien - 1; i++)
		cout << static_cast<char>(65 + i) << ", ";
	cout << static_cast<char>(65 + nbien - 1) << ") = ";
	cout << static_cast<char>(228) << "m(";
	rewind(stdin);
	getline(cin, s);
	vector<string> tokens = Tokenizer::Parse(s, seperator);
	//Chuyển mintern về dạng nhị phân
	for (int i = 0; i < tokens.size(); i++)
	{
		for (int i2 = 0; i2 < mintern.size(); i2++)//Ban đầu các giá trị đều bằng 0
			mintern[i2] = 0;
		temp = stoi(tokens[i]);
		count = nbien - 1;
		while (count>=0 && temp > 0)//Gán từ phải qua trái
		{
			mintern[count] = temp % 2;
			temp = temp / 2;
			count--;
		}
		Data.push_back(mintern);
	}
	cout << "Nhap cac mintern khong xac dinh: ";
	cout << static_cast<char>(228) << "m(";
	getline(cin, s);
	if (s != "") {
		vector<string> tokens = Tokenizer::Parse(s, seperator);
		for (int i = 0; i < tokens.size(); i++)
		{
			for (int i2 = 0; i2 < mintern.size(); i2++)
				mintern[i2] = 0;
			temp = stoi(tokens[i]);
			count = nbien - 1;
			while (count >= 0 && temp > 0)
			{
				mintern[count] = temp % 2;
				temp = temp / 2;
				count--;
			}
			Datav2.push_back(mintern);
		}
	}
}

int He10(vector<int> a) {
	int temp = 0;
	int heso = 1;//Từ vị trí cuối đến vị trí đầu, mỗi lần nhảy hệ số tăng lên 2
	for (int i = a.size()-1; i >= 0; i--)
	{
		if (a[i] == 1) temp += heso;
		heso *= 2;
	}
	return temp;
}
bool Isrepeat(int n, vector<int> Data, int& pos)
{
	for (int i = 0; i < Data.size(); i++)//Duyệt từ đầu mảng đến cuối mảng, nếu  phân tử nào bằng n thì return true và gán pos bằng vị trí đó
		if (n == Data[i])
		{
			pos = i;
			return true;
		}
	return false;//Nếu không thì return false
};
bool other1(vector<int> v1, vector<int> v2, int& pos) {
	int count = 0;
	for (int i = 0; i<v2.size() ; i++)//Duy chuyển lần lượt qua từng vị trí của 2 mintern(dạng nhị thức)
		if (v1[i] != v2[i])//Nếu khác thì tăng biến count và dùng pos để giữ vị trí khác
		{
			count++;
			pos = i;
		}
	if (count == 1) return true;//Nếu chỉ có 1 điểm khác( count = 1) thì return true;
	else return false;//Nếu không thì return false.
}
void OutCom(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {// Duyệt đến hết các mã nhị phân
		for (int j = 0; j < v.at(i).size(); j++)//Duyệt từng phần tử trong mã nhị phân
		{
			//Chuyển vị trí của các phần tử (int) về dạng ký tự (vị trí 0 thì là ký tự A...)
			if (v.at(i).at(j) == 1)cout << static_cast<char>(65 + j);//Nếu bằng 1 thì ko in dấu ' phía sau và ngược lại
			if (v.at(i).at(j) == 0) cout << static_cast<char>(65 + j)<< '\'';
		}
		if (i < v.size() - 1) cout << " + ";//Nếu chưa phải là mã nhị phân cuối cùng thì in thêm dấu + 
	}
}
void Bool::OutMin() {
	if (cData.size() <= 0 && Option.size() <= 0)//Trường hợp F rỗng
	{
		cout << "F trong!";
		return;
	}
	if (Option.size() < 2)//Trường hợp chỉ có 1 công thức đa tối tiểu
	{
		cout << "Cong thuc toi tieu ham bool: " << endl;
		cout << "F = ";
		OutCom(cData);//Xuất tổ hợp biến mặc định
		for (int i = 0; i < Option.size(); i++) {//Xuất tổ hợp biến không bắt buộc(nhưng tối tiểu)
			cout << " + ";
			OutCom(Option.at(i));
		}
		cout << endl;
	}
	else//Trường hợp có nhiều công thức đa thức tối tiểu
	{
		cout << "Ham bool co " << Option.size() << " cong thuc toi tieu: " << endl;
		for (int i = 0; i < Option.size(); i++)//Lần lượt xuất ra các công thức tối tiểu
		{
			cout << "F = ";
			OutCom(cData);
			cout << " + ";
			OutCom(Option.at(i));
			cout << endl;
		}
	}
}
bool Islike(vector<vector<int>> v, int &count) {//Kiểm tra xem các phần tử có bằng nhau hay không
	if (v.size() < 2)//Nếu số phần tử <2 thì return true, count dùng để giữ số công thức tối tiểu sẽ được tạo ra(phục vụ cho đệ quy)
	{
		count = 1;
		return true;
	}
	else {//Nếu số phần tử >=2 thì kiểm tra v[0] với các v[i], nếu có t/h khác thì return true, ngược lại return true
		for (int i = 1; i < v.size(); i++)
			if (v[0] != v[i]) return false;
		count = v.size();
		return true;
	}

}
vector<int> Delline(vector<vector<int>> &v, int line)//Hàm xóa 1 phần tử nào đó trong v (dòng)
{
	int vt;
	vector<int>posdel;// giữ địa chỉ các dòng bị xóa theo
	for (int i = 0; i < v.size(); i++)//Phần tử nào trong các dòng trùng với phần tử trong dòng line thì bị xóa
	{
		if (i == line) continue;// Quay lại for
		for (int j = 0; j < v.at(line).size(); j++)
			if (Isrepeat(v.at(line).at(j), v.at(i), vt))// Trùng thì xóa
				v.at(i).erase(v.at(i).begin() + vt);
	}
	v.erase(v.begin() + line);//Sau đó xóa dòng line
	for (int i = 0; i < v.size(); i++)// Sau khi xóa, nếu dòng nào rỗng thì lưu chỉ số dòng vào posdel, rồi xóa dòng đó và 
		if (v.at(i).empty() == true) posdel.push_back(i);
	for (int i = 0; i < v.size(); i++)
		if (v.at(i).empty() == true)
		{
			v.erase(v.begin() + i);
			i--;
		};
	return posdel;//trả về vector chứa các dòng bị xóa
}
bool Islike(vector<vector<int>> v1, vector<vector<int>> v2)
{
	int i1 = 0, i2 = 0;
	if (v1.size() != v2.size()) return false; // Nếu số phần tử không bằng nhau thì chúng không giống nhau
	else {
		for (i1 = 0; i1 < v1.size(); i1++)// Kiểm tra từng phần tử trong v1 có bằng phần tử nào trong v2 hay không
		{
			for (i2 = 0; i2 < v2.size(); i2++)
				if (v1.at(i1) == v2.at(i2)) break;
			if (i2 >= v2.size()) return false;//Nếu không có phần tử nào trong v2 bằng (khi chạy hết hàm for) thì return false
		}
		return true; // Nếu như tất cả đều trùng thì return true;
	}
}
int NumShort(vector<vector<int>> v)
{
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v.at(i).size(); j++)
			if (v.at(i).at(j) == -1) n++;// Nếu tại đó giá trị bằng -1 (tại đó đã được rút gọn) thì tăng n;
	return n;//Trả về tổng số vị trí đã được rút gọn của các tổ hợp biến
}
int NumShort(vector<int> v)
{
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i] == -1) n++;
	return n;// Trả về số vị trí đã được rút gọn của 1 tổ hợp biến
}
void Bool::MinBool() {
	int count = 0, check = 0;
	int pos = 0;//Lưu các vị trí khi cần
	vector<int> sl;
	vector<int> temp;//Biến tạm dùng khi cần
	//Biến đặc biệt(là ký tự đầu của tên 2 thành viên trong nhóm)
	vector<vector<int>> PS; //dùng để lưu các tổ hợp biến được chọn(Không thuộc tổ hợp nào lớn hơn nữa)
	vector<vector<int>> H10PS;//dùng để lưu hệ 10 các tổ hợp biến được chọn
	vector<vector<int>> H10;//Lưu các tổ hợp dạng thập phân
	vector< vector<int>> H10v2;//Lưu các tổ hợp dạng thập phân
	vector< vector<int>> cData2;//Lưu các tổ hợp dạng nhị phân
	for (int i = 0; i < Data.size(); i++)//Chuyển các biến từ dạng nhị phân sang thập phân và lưu vào H10v2
	{
		temp.push_back(He10(Data[i]));
		H10v2.push_back(temp);
		temp.clear();
	}
	vector<int> kt;//Dùng để lưu trạng thái của các tổ hợp biến đã được gộp hay chưa
	cData = Data;//Gán cData = Data vì ta sẽ không làm việc trên Data
	H10 = Datav2;//Tương tự
	for (int i = 0; i < H10.size(); i++)//Kiểm tra xem có biến xác định nào trùng với biến không xác định hay không. Nếu có xem nó là không xác định
	{
		check = false;
		for (int i2 = 0; i2 < cData.size(); i2++)
		{
			if (H10.at(i) == cData.at(i2))
			{
				H10v2.at(i2).clear();//Nếu trùng thì chuyển nó về không xác định(Không có hệ 10)
				check = true;
			}
		}
		if (check == true)//Nếu có trùng thì xóa biến không xác định ra khỏi vector
		{
			H10.erase(H10.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < Datav2.size(); i++)
	{
		cData.push_back(Datav2.at(i));//Copy các biến không xác định(dạng nhị phân) vào xác định nhưng ko có hệ 10 tương ứng(để xác định là kxd)
		H10v2.push_back(temp); // temp lúc này emty
	}
	H10.clear();
	while (cData.empty() == false)//Gộp các tổ hợp biến cho đến khi nào không gộp được nữa thì thôi
	{
		kt.resize(H10v2.size());//Xác định trạng thái tổ hợp biến đã được gộp hay chưa
		for (int i = 0; i < kt.size(); i++)
			kt[i] = 1;
		H10 = H10v2;
		H10v2.clear();
		cData2 = cData;
		cData.clear();
		for (int i = 0; i < cData2.size() - 1; i++)// duyệt các phần tử trong vector 
			for (int j = i + 1; j < cData2.size(); j++)
				if (other1(cData2[i], cData2[j], pos))//Nếu tổ hợp biến khác nhau tại 1 phần tử(có thể gộp) thì gộp
				{
					cData.push_back(cData2[i]);
					cData.back()[pos] = -1;// tại phần tử khác nhau đó ta gán bằng -1(Đánh dấu đã được rút gọn)
					H10v2.push_back(H10.at(i));// Sau đó t gộp hệ 10 hai tổ hợp biến lại với nhau
					for (int t = 0; t < H10.at(j).size(); t++)
						H10v2.back().push_back(H10.at(j).at(t));
					for (int k = 0; k < cData.size() - 1; k++) if (cData.back() == cData[k])//Nếu tổ hợp sau khi gộp đã có trước đó thì xóa đi
					{
						cData.pop_back();//Xóa tổ hợp dạng nhị phân và thập phân
						H10v2.pop_back();
						break;
					}

					kt.at(j) = 0;//Đánh dấn tổ hợp biến đã được gộp
					kt.at(i) = 0;
				}

		for (check = 0; check < kt.size(); check++)//Chạy kiểm tra
			if (kt[check] == 1)// Phần tử nào không được gộp thì thêm vào PS và H10PS tương ứng
			{
				PS.push_back(cData2[check]);
				H10PS.push_back(H10.at(check));
			}
	}
	
	H10v2 = H10PS;
	cData = PS;

	cData2.clear();
	temp.clear();
	for (int i1 = 0; i1 < H10v2.size(); i1++)//Tìm các tổ hợp biến bắt buộc
	{
		for (count = 0; count < H10v2[i1].size(); count++)
		{
			check = false;
			for (int i2 = 0; i2 < H10v2.size(); i2++)
			{
				if (i1 == i2) continue;
				//Kiểm tra các biến(dạng thập phân) có bằng với biến thuộc các tổ hợp khác không
				if (Isrepeat(H10v2.at(i1).at(count), H10v2[i2], pos) == true)
				{
					check = true;
					break;
				}
			}
			if (check == false) break;
		}
		if (count < H10v2[i1].size())//Nếu có biến chỉ mình nó có( chạy hết vòng for) thì nó là bắt buộc
		{
			cData2.push_back(cData[i1]);// Thêm tổ hợp biến bắt buộc vào cData2
			temp.push_back(i1);
			for (int i2 = 0; i2 < H10v2.size(); i2++)//Xóa các biến của các dòng khác nếu trùng với biến trong tổ hợp bắt buộc
			{
				if (i1 == i2) continue;
				for (int j = 0; j< H10v2[i1].size(); j++)
					if (Isrepeat(H10v2[i1][j], H10v2[i2], pos) == true)
						H10v2[i2].erase(H10v2[i2].begin() + pos);

			}
			cData.erase(cData.begin() + i1);// Xóa các tổ hợp bắt buộc ra khỏi vector
			H10v2.erase(H10v2.begin() + i1);
			i1--;
		}
	}
	//Loại các nhóm chỉ chứa tổ hợp biến không xác định
	if (Datav2.size() > 0) {
		for (int i = 0; i < H10v2.size(); i++)
			if (H10v2.at(i).empty())
			{
				H10v2.erase(H10v2.begin() + i);
				cData.erase(cData.begin() + i);
				i--;
			}
	}
	int step = 0;
	
	SetMin(H10v2, cData, step);
	//Xóa các tổ hợp giống nhau
	for (int i = 0; i+1 < Option.size(); i++) {
		for (int j = i + 1; j < Option.size(); j++)
			if (Islike(Option.at(i), Option.at(j))) {
				Option.erase(Option.begin() + j);
				j--;
			};
	}
	//Tìm các tổ hợp biến tối tiểu nhất
	if (Option.size() > 1)
	{
		check = Option.at(0).size();
		count = NumShort(Option.at(0));
		for (int i = 1; i < Option.size(); i++)
		{
			if (Option.at(i).size() < check)//So sánh số lượng tổ hợp biến
			{
				check = Option.at(i).size();
				count = NumShort(Option.at(i));
			}
			if (Option.at(i).size() == check && NumShort(Option.at(i)) > count)// So sách số lượng vị trí rút gọn
			{
				count = NumShort(Option.at(i));
			}
		}
		for (int i = 0; i < Option.size(); i++) {//Sau đó xóa nhưng công thức tổ hợp không tối tiểu đi
			if (Option.at(i).size() != check || NumShort(Option.at(i)) != count)
			{
				Option.erase(Option.begin() + i);
				i--;
			}
		}
		//Sắp xếp lại các tổ hợp biến cho đẹp(selection short)
		for (int i = 0; i < Option.size(); i++) {
			for (int i2 = 0; i2 < Option.at(i).size() - 1; i2++)
			{
				check = i2;
				for (int j = i2 + 1; j < Option.at(i).size(); j++)
					if (NumShort(Option.at(i).at(j))> NumShort(Option.at(i).at(check)))
						check = j;
				if(check !=i2) swap(Option.at(i).at(i2), Option.at(i).at(check));
			}
		}
	}
	cData = cData2;
	//Sắp xếp lại các tổ hợp biến cho đẹp(selection short)
	if (cData.size() > 1) {
		for (int i = 0; i + 1 < cData.size(); i++)
		{
			check = i;
			for (int j = i + 1; j < cData.size(); j++)
				if (NumShort(cData.at(j)) > NumShort(cData.at(check)))
					check = j;
			if (check != i) swap(cData.at(i), cData.at(check));
		}
	}
}
vector<int> Posmax(vector<vector<int>> v) {
	vector<int> max;
	int m = 0;
	for (int i = 1; i < v.size(); i++)
		if (v.at(i).size() > v.at(m).size()) m = i;//Tìm số lượng phần tử lớn nhất của các vector con là bao nhiêu
	for (int i = 0; i < v.size(); i++)
		if (v.at(i).size() == v.at(m).size()) max.push_back(i);// Lưu vị trí các vector con có số phần tử lớn nhất
	return max;
}
//Hàm tìm công thức tối tiểu từ các tổ hợp không bắt buộc
int Bool::SetMin(vector<vector<int>> v, vector<vector<int>> Data, int& step)
{
	step++; 
	int sl;
	int count=0;
	vector<int>posdel;
	vector<vector<int>> temp;
	vector<vector<int>> tempData;
	if (Islike(v,count)) {//Kiểm tra các vector các có bằng nhau hay không
		if (v.size() == 0 && step!=1)//Nếu vector rỗng và đang ở trạng thái gọi đệ quy
		{
			temp.clear();
			Option.push_back(temp);
		}else
		for (int i = 0; i < v.size(); i++)
		{
			temp.clear();
			temp.push_back(Data.at(i));
			Option.push_back(temp);
		}
		return count;// Trả về số vector(tổ hợp biến) đã được thêm
	}
	vector<int> max = Posmax(v);//Cac tổ biến  chứa nhiều biến chưa được chọn nhất 
	int a = 0;
	for (int i = 0; i < max.size(); i++)//Chọn lần lượt các tổ hợp biến đó
	{
		tempData.clear();
		temp.clear();
		temp = v;
		posdel = Delline(temp, max[i]);//temp lưu trữ các tổ hợp biến chưa được chọn
		for (int i2 = 0; i2 < Data.size(); i2++)
		{
			if (i2 == max[i]) continue;
			tempData.push_back(Data.at(i2));
		}
		for (int i2 = posdel.size()-1;i2>=0; i2--) // Xóa các dòng mà chứa các biến đã được chọn
			tempData.erase(tempData.begin() + posdel[i2]);
		sl = SetMin(temp, tempData,step);//Gọi đệ quy cho đến khi chỉ các các vector(tổ hợp) bằng nhau hoặc chỉ còn <2 phần tử
		a += sl;//lưu tổng số lượng tổ hợp đã được tạo ra
		for (int i2 = 0; i2 < sl; i2++)
		{
			Option.at(Option.size() - 1 - i2).push_back(Data.at(max[i])); //Sau khi tạo các tổ hợp thì thêm vào các biến trước đó
		}
	}
	return  a;//tổng số lượng tổ hợp đã được tạo ra
}

Bool::~Bool() {
}
