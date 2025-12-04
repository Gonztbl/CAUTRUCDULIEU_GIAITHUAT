#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;
class sinhvien{
	private: 
	
	char hoten[30];
	int toan, ly , hoa;
	public:
		void nhap();
		void xuat();
	friend istream & operator>>(istream&in, sinhvien&a);
	friend ostream & operator<<(ostream&out, sinhvien&a);
};
istream & operator>>(istream&in, sinhvien&a)
{
	cout<<"\n Nhap thong tin sinh vien"<<endl;
	cout<<"\n ho ten: "; fflush(stdin); gets(a.hoten);
	cout<<"\n nhap diem toan:"; in>>a.toan;
	cout<<"\n nhap diem ly: "; in>>a.ly;
	cout<<"\n Nhap diem hoa: "; in>>a.hoa;
	return in;
}
ostream & operator<<(ostream&out, sinhvien&a){
	cout<<"\n Thong tin sinh vien: ";
	out<<a.hoten<<" |"<<a.toan<<" "<<a.ly<<" "<<a.hoa;
	return out;
}
int main(){
	sinhvien a;
	cin>>a;
	cout<<a;
}
