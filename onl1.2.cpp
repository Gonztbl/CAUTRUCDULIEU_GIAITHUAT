#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h> 

using namespace std;

class sinhvien;
class mon;
class phieu;

class sinhvien{
	char masv[30];
	char tensv[30];
	char lop[6];
	int khoa;
friend class phieu; 
	public:
		void nhap();
		void xuat();
		
}; 
class mon{
	char tenmon[30];
	int sotrinh;
	float diem;
friend void dem(phieu a); 
friend class phieu; 
	public:
		void nhap();
		void xuat();
};
class phieu{
	sinhvien sv;
	mon m[50];
	int n;
	
	friend void dem(phieu a); 
	
	friend class mon;
	friend class sinhvien;  
	public:
		void nhap();
		void xuat();
};
void sinhvien::nhap(){
	cout<<"\n nhap ma sinh vien: "; fflush(stdin); gets(masv);
	cout<<"\n nhap ten sinh vien: "; fflush(stdin); gets(tensv);
	cout<<"\n nhap ten lop: "; fflush(stdin); gets(lop);
	cout<<"\n nhap khoa: "; cin>>khoa; 
}
void sinhvien::xuat(){
	cout<<setw(10)<<"masv: "<<masv<<setw(30)<<"tensv: "<<tensv<<endl;
	cout<<setw(10)<<"lop: "<<lop<<setw(30)<<"khoa: "<<khoa<<endl; 
}
void mon::nhap(){
	cout<<"\n nhap ten mon: ";     fflush(stdin);gets(tenmon);
	cout<<"\n nhap so trinh: ";    cin>>sotrinh;
	cout<<"\n nhap diem: ";        cin>>diem;
}
void mon::xuat(){
	cout<<setw(10)<<tenmon<<setw(30)<<sotrinh<<setw(30)<<diem<<endl;
	
}
void phieu::nhap(){
	cout<<"\n --------nhap thong tin sinh vien------"<<endl;
	sv.nhap();
	cout<<"\n nhap so mon: "; cin>>n;
	for(int i=0; i<n; i++){
		m[i].nhap();
		
	}
}
void phieu::xuat(){
	cout<<"\n              PHIEU BAO DIEM              "<<endl;
	sv.xuat();
	cout<<setw(10)<<"BANG DIEM: "<<endl;
	cout<<setw(10)<<"tenmon"<<setw(30)<<"sotrinh"<<setw(30)<<"diem"<<endl;
	for(int i=0; i<n; i++){
		m[i].xuat();
	}
	
	//tinh diem trung binh 
	float t=0; 
	float tt=0; 
	for(int i=0; i<n; i++)
{
   t = t + m[i].sotrinh*m[i].diem ; 
  tt = 	tt + m[i].sotrinh ;
 
		 
}
float dtb;
      dtb=t/tt;
	 cout<<setw(60)<<"DIEM TRUNG BINH: "<<dtb;

}

//yeu cau xuat ten mon hoc co so trinh lon hon 3 
void dem(phieu a){

	for(int i=0; i<3; i++)
{
 a.m[i].sotrinh>3;
 a.m[i].xuat();	
}
} 
int main(){
	phieu a;
	a.nhap();
	a.xuat();
	cout<<"\n mon hoc so trinh lon hon 3: "; 
    dem(a); 
	return 0;
	
}

