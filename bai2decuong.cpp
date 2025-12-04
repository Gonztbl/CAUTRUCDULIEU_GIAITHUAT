#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
using namespace std;

class phieu;
class thuoc;
class benhnhan;
class bacsi;

class benhnhan{
	private:
		char ten[30];
		char gioitinh[5];
		char ngaynhap[30];
		int thoigian;
	public:
		void nhap();
	friend class phieu;
};
class thuoc{
	private:
		char tenthuoc[40];
		char donvi[30];
		int soluong;
		char lieu[30];
	public:
		void nhap();
		void xuat();
};
class bacsi{
	private:
		char tenbs[39];
	public:
		void nhap();
	friend class phieu;
};
class phieu{
	private:
		benhnhan a;
		bacsi x;
		thuoc y[50];
		int n;
	public:
		void nhap();
		void xuat();
	friend class bacsi;
	friend class benhnhan;
};
void benhnhan::nhap(){
	cout<<"\n--------Nhap thong tin benh nhan--------------"<<endl;
	cout<<"\n Nhap ho ten: "; fflush(stdin); gets(ten);
	cout<<"\n Nhap gioi tinh: "; fflush(stdin); gets(gioitinh);
	cout<<"\n Nhap thoi gian dieu tri: ";cin>>thoigian;
	cout<<"\n Nhap ngay nhap vien: "; fflush(stdin); gets(ngaynhap);
}
void thuoc::nhap(){
	cout<<"\n------------Nhap thong tin loai thuoc dieu tri------------";
	cout<<"\n Ten thuoc: "; fflush(stdin); gets(tenthuoc);
	cout<<"\n Don vi tinh: "; fflush(stdin); gets(donvi);
	cout<<"\n So luong: "; cin>>soluong;
	cout<<"\n Lieu Luong "; fflush(stdin); gets(lieu);
}
void thuoc::xuat(){
	cout<<setw(5)<<tenthuoc<<setw(20)<<donvi<<setw(20)<<soluong<<setw(20)<<lieu<<endl;
}
void bacsi::nhap(){
	cout<<"\n ----NHAP THONG TIN BAC SI-----"<<endl;
	cout<<"\n Nhap ten bac si: "; fflush(stdin); gets(tenbs);
}
void phieu::nhap(){
	cout<<"\n -------NHAP THONG TIN PHIEU THEO DOI DIEU TRI BENH NHAN-------"<<endl;
	a.nhap();
	x.nhap();
	cout<<"\n Nhap so loai thuoc: "; cin>>n;
	for(int i=0; i<n; i++){
	cout<<"\n Nhap thong tin thuoc so "<<i+1<<endl;
	y[i].nhap();}
	
}
void phieu::xuat(){
	cout<<"\n                      PHIEU THEO DOI DIEU TRI BENH NHAN                     "<<endl;
    cout<<setw(5)<<"Ngay nhap vien: "<<a.ngaynhap<<setw(20)<<"Bac si dieu tri: "<<x.tenbs<<endl;
    cout<<setw(5)<<"Ho va ten benh nhan: "<<a.ten<<setw(25)<<"Gioi tinh: "<<a.gioitinh<<endl;
    cout<<setw(5)<<"Thoi gian dieu tri: "<<a.thoigian<<"ngay"<<endl;
    cout<<setw(5)<<"DANH MUC NHUNG LOAI THUOC DIEU TRI "<<endl;
    cout<<setw(5)<<"Ten Thuoc"<<setw(20)<<"Don vi tinh"<<setw(20)<<"So luong"<<setw(20)<<"Lieu luong/1 ngay"<<endl;
  for(int i=0; i <n; i++){
  	y[i].xuat();
  }
}


int main(){
	phieu p;
	p.nhap();
	p.xuat();
	return 0;
}