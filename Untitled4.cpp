//tinh tong s=1/2+1/4+...+1/(2*n)
#include<iostream>
using namespace std;
float bai04(int n)
{
	if(n==1)//vi 1/2*1=1/2
	{return 1/2;
	}
	else
	{
		return bai04(n-1)+(float)1/(2*n);
		//sử dụng ép kiểu cho gia tri không thuộc số nguên 

	}
}
int main()
{
	int n;
	cout<<"nhap n: ";
	cin>>n;
	cout<<"gia tri cua day so la: "<<bai04(n);
}