#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;
class phieu;
class ncc;
class sp;

class ncc{
	private:
		char mancc[30];
		char tenncc[30];
		char diachi[30];
		char sdt[10];
	public:
		void nhap();
		void xuat();
	friend class phieu;	
};
class sp{
	private:
		char masp[30];
		char tensp[20];
		int soluong;
		int dongia;
	public:
		void nhap();
		void xuat();
		long getTT(){
	 return dongia*soluong;}
	friend class phieu;
};
class phieu{
	private:
		sp x[50];
		int n;
		ncc y;
		char maphieu[30];
		char ngaylap[30];
	public:
		void nhap();
		void xuat();
		//----tinh tong
		long tongtt();
		////
	friend class sp;
	friend class ncc;
};
void sp::nhap(){
	cout<<"\n Nhap ma san pham: "; fflush(stdin); gets(masp);
	cout<<"\n Nhap ten san pham: "; fflush(stdin); gets(tensp);
	cout<<"\n Nhap so luong: "; cin>>soluong;
	cout<<"\n Nhap gia tien: "; cin>>dongia;
}
void sp::xuat(){
	cout<<setw(5)<<masp<<setw(20)<<tensp<<setw(20)<<soluong<<setw(20)<<dongia<<setw(20)<<dongia*soluong<<endl;
	
}
void ncc::nhap(){
	cout<<"\n Nhap ten nha cung cap: "; fflush(stdin); gets(tenncc);
	cout<<"\n Nhap ma nha cung cap: "; fflush(stdin); gets(mancc);
	cout<<"\n Nhap dia chi nha cung cap: "; fflush(stdin); gets(diachi);
	cout<<"\n Nhap so dien thoai: "; fflush(stdin); gets(sdt);
}
void ncc::xuat(){
	cout<<setw(5)<<"Ma nha cung cap: "<<mancc<<setw(30)<<"Ten nha cung cap: "<<tenncc<<endl;
	cout<<setw(5)<<"Dia chi: "<<diachi<<setw(30)<<"SDT: "<<sdt<<endl;
}
void phieu::nhap(){
	cout<<"\n Nhap ma phieu: "; fflush(stdin); gets(maphieu);
	cout<<"\n Nhap ngay lap: "; fflush(stdin); gets(ngaylap);
	y.nhap();
	cout<<"\n Nhap so luong cac loai san pham: "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"\n Nhap thong tin san pham so "<<i+1<<endl;
		x[i].nhap();
		
	}
}

 long phieu::tongtt(){
 	
	long t=0;
for(int i=0;i<n;i++){
	t=t+x[i].getTT();
	}
	return t;
}
void phieu::xuat(){
	cout<<"DAI HOC VICTORY"<<endl;
	cout<<"---------------------------------PHIEU NHAP VAN PHONG PHAM----------------"<<endl;
	cout<<setw(5)<<"Ma phieu:     "<<maphieu<<setw(30)<<"Ngay lap:  "<<ngaylap<<endl;
	y.xuat();
	cout<<setw(5)<<"Ma SP"<<setw(20)<<"Ten san pham"<<setw(20)<<"So Luong"<<setw(20)<<"Don gia"<<setw(20)<<"Thanh tien"<<endl;
	for(int i=0; i<n; i++){
		x[i].xuat();
	}
cout<<setw(50)<<"Tong: "<<tongtt();
cout<<setw(10)<<"Hieu truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap";
}



int main(){
	phieu p;
	p.nhap();
	p.xuat();
	return 0;
}