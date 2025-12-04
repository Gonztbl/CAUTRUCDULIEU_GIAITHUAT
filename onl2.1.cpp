#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class school;
class person;
class faculty;
class student;

class school{
	private:
		char names[30];
		char dates[10];
		friend class faculty;
		   friend void sua(student &a);
class faculty{
	private:
		char namef[30];
		char datef[10];
		  school x;
	friend class school;
	friend class student;
	   friend void sua(student &a);
	   
	public:
		void nhap();
		void xuat();
};
class person{
	protected:
		char namep[30];
		char birth[30];
		char address[30];
	public:
		void nhap();
		void xuat();
	
};
class student:public person{
	private:
	
		char Class[30];
        float score;
        friend void sua(student &a);
        faculty y;
    public:
    	void nhap();
    	void xuat();
    
    	
		
};
void faculty::nhap(){
	cout<<"\n nhap ten truong: ";           fflush(stdin); gets(x.names);
	cout<<"\n nhap nam thanh lap truong: "; fflush(stdin); gets(x.dates);
	cout<<"\n nhap ten khoa: ";             fflush(stdin); gets(namef);
	cout<<"\n nhap nam thanh lap khoa: ";   fflush(stdin); gets(datef);
}
void faculty::xuat(){
	cout<<"\n school name: "<<x.names;
	cout<<"\n date shool: "<<x.dates;
	cout<<"\n faculty name: "<<namef;
	cout<<"\n faculty date: "<<datef;
}
void person::nhap(){
	cout<<"\n nhap ten sinh vien: ";       fflush(stdin); gets(namep);
	cout<<"\n nhap ngay sinh sinh vien: "; fflush(stdin); gets(birth);
	cout<<"\n nhap dia chi sinh vien: ";   fflush(stdin); gets(address);
	
}
void person::xuat(){
	cout<<setw(10)<<"ten sinh vien: "<<namep<<setw(20)<<"ngay sinh: "<<birth<<setw(20)<<"dia chi:"<<address<<endl;
}
void student::nhap(){
	person::nhap();
	cout<<"\n nhap ten lop: ";             fflush(stdin); gets(Class);
	cout<<"\n nhap diem: ";                               cin>>score;
	y.nhap();
}
void student::xuat(){
	person::xuat();
	cout<<"\n ten lop: "<<Class;
	cout<<"\n diem: "<<score;
	y.xuat();
	
}
void sua(student &a){
	strcpy(a.y.x.names,"DHCN");
}
int main(){
	student a;
	a.nhap();
	a.xuat();
	sua(a);
	a.xuat();
	return 0;
	}