//bai 02: tinh tong cua s(n)=1*1+2*2+3*3+..+n*n
//s(n)=1+...+(n-1)(n-1)+(n*n)
#include<iostream>
using namespace std;
int bai02(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return bai02(n-1)+n*n;
	}
}
int main()
{
	int n;
	cout<<"nhap n: ";
	cin>>n;
	cout<<endl;
	cout<<"gia tri cua S(n)= "<<bai02(n);
	
}