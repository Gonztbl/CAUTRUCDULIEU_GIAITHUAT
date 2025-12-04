#include<iostream>

using namespace std;

class sp{
	private:
		int ts, ms;
	public:
	void nhap();
	
	void xuat();
	
	friend istream operator>>(istream&in, sp &y);
	friend ostream operator<<(ostream&out, sp y);
	sp operator+(sp y);
	//toan tu cong hai so
	sp operator-(sp y);
	//toan tu tru hai so
	//toan tu doi dau
	sp operator-();
	
	
};
void sp::nhap(){
	cout<<"\n Nhap tu so:"; cin>>ts;
	cout<<"\n Nhap mau so: "; cin>>ms;
	
}
void sp::xuat(){
	cout<<"phan so: "<<ts<<"/"<<ms<<endl;
}
sp sp::operator+(sp y){
	sp z;
	z.ts=ts*y.ms+ms*y.ts;
	z.ms=ms*y.ms;
	return z;
}
sp sp::operator-(sp y){
	sp z;
	z.ts=ts*y.ms-ms*y.ts;
	z.ms=ms*y.ms;
	return z;
}
sp sp::operator-(){
	sp z;
	z.ts=-ts;
	z.ms=ms;
	return z;
	
}
int main(){
	sp x, y;
x.nhap() ; y.nhap() ;
sp z = x + y ; //sử dụng phép cộng
cout<<"\n tong hai so "<<endl;
z.xuat() ;
sp j = -z ; //sử dụng phép đổi dấu
cout<<"\n Doi dau phep cong"<<endl;
j.xuat();
sp t = x - y ; //sử dụng phép trừ
cout<<"\n Hieu hai so"<<endl;
 t.xuat() ; 
}