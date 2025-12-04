//on thi oop
#include<iostream>
//thu vien nhap xuat
#include<iomanip>
//thu vien dung setw
#include<string.h>
//thu vien dung mang 
#include<fstream>
//thu vien luu file 

using namespace std;
class hang;// lop cha
class hop;// ke thua lop hang
class gianhang;//ket tap 1-n
class hang{
	protected:
		char mahang[30];
		char loai[30];
		char namsx[10]; // d/m/y
		char hangsx[30];
	public:
		void nhap();
		void xuat();
};
class hop:public hang{
	private:
		char kieudang[30];
		char chatlieu[30];
		float thetich;
		char ghichu[30];
	public:
		void nhap();
		void xuat();
		
};
class gianhang{
	private:
	    char magh[30];
	    char tengh[30];
	    float dientich;
	    hop x[30];;
	    int n;
	public:
		void nhap();
		void xuat();
	
};
void hang::nhap()
{
	cout<<"\n----------- Nhap thong tin hang--------"<<endl;
	cout<<"\n Nhap ma hang: "; fflush(stdin); gets(mahang);
	cout<<"\n Nhap loai hang: "; fflush(stdin); gets(loai);
	cout<<"\n Nhap nam san xuat: "; fflush(stdin); gets(namsx);
	cout<<"\n Nhap hang san xuat: "; fflush(stdin); gets(hangsx);
}
void hang::xuat()
{
	cout<<setw(5)<<"Ma Hang: "<<mahang<<endl;
	cout<<setw(5)<<"Loai: "<<loai<<endl;
	cout<<setw(5)<<"Nam san xuat: "<<namsx<<endl;
	cout<<setw(5)<<"Hang san xuat: "<<hangsx<<endl;
}
void hop::nhap()
{
	cout<<"\n--------Nhap thong tin hop---------"<<endl;
	cout<<"\n Nhap kieu dang: "; fflush(stdin); gets(kieudang);
	cout<<"\n Nhap chat lieu: "; fflush(stdin); gets(chatlieu);
	cout<<"\n Nhap the tich: "; cin>>thetich;
	cout<<"\n Nhap ghi chu: "; fflush(stdin); gets(ghichu);
}
void hop::xuat()
{
	cout<<"\n --------Thong tin hop---------"<<endl;
	cout<<"\n  Kieu dang: "<<kieudang<<endl;
	cout<<"\n Chat lieu: "<<chatlieu<<endl;
	cout<<"\n The tich: "<<thetich<<endl;
	cout<<"\n Ghi chu: "<<ghichu<<endl;
	
}
void gianhang::nhap()
{
	cout<<"\n------------Nhap thong tin gian hang------------------"<<endl;
}
class hop
int main(){
	gianhang gh;
	gh.nhap();
	gh.xuat();
	return 0;
	
}