#include<iomanip>
#include<iostream>

using namespace std;

class nguoi;
class benhvien;
class benhnhan;

class nguoi{
	protected:
		char hoten[30];
		int tuoi;
	friend int dem(benhnhan a[50], int n);
	public:
		void nhap();
		void xuat();

};
class benhvien{
	protected:
		char tenbv[30];
		char diachi[30];
		char giamdoc[30];
			nguoi x;
		friend	int dem(benhnhan a[50], int n);
	friend class benhnhan;
		
		
};
class benhnhan:public nguoi{
	private:
		char ma[20];
		char tiensu[30];
		char chuandoan[20];
		benhvien y;
	friend int dem(benhnhan a[50], int n);
	public:
		void nhap();
		void xuat();
};
void nguoi::nhap(){
	cout<<"\n Nhap ho ten: "; fflush(stdin); gets(hoten);
	cout<<"\n Nhap so tuoi: "; cin>>tuoi;
}
void nguoi::xuat(){
    cout<<"\n Hoten: "<<hoten;
    cout<<"\n Tuoi: "<<tuoi<<endl;
}
void benhnhan::nhap(){
		nguoi::nhap();
	cout<<"\n Nhap ma: "; fflush(stdin); gets(ma);
	cout<<"\n Nhap tien su: "; fflush(stdin); gets(tiensu);
	cout<<"\n Nhap chuan doan: "; fflush(stdin); gets(chuandoan);
   cout<<"\n Nhap ten benh vien: "; fflush(stdin); gets(y.tenbv);
   cout<<"\n Nhap dia chi: "; fflush(stdin); gets(y.diachi);
   cout<<"\n Nhap ten giam doc: "; fflush(stdin); gets(y.giamdoc);

}
void benhnhan::xuat(){
	cout<<"\n Ma: "<<ma;
	cout<<"\n Tien su: "<<tiensu;
	cout<<"\n Chuan doan: "<<chuandoan;
	cout<<"\n ten benh vien: "<<y.tenbv;
	cout<<"\n dia chi: "<<y.diachi;
	cout<<"\n giam doc: "<<y.giamdoc<<endl;
}
 int dem(benhnhan a[50], int n){
 int dem=0;
 	for(int i=1; i<n; i++){
	 
 	if(30<a[i].tuoi)
 	dem++;}
 	return dem;
 	
 }
int main(){
	benhnhan a[50];
	int n;
	cout<<"\n nhap so luong benh nhan: "; cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<"\n benh nhan so: "<<i+1;
		a[i].nhap();
	}
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
	dem(a,n);

	//bonus1 
	return 0;
}