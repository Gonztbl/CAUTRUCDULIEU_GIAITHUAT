//Tính tổng S(n)= 1/2+ 2/3+ 3/4+...+n/n+1
#include<iostream>
using namespace std;
float bai07(int n)
{
	if(n==1)
	{return (float) 1/2;
	}
	else
	{
		return bai07(n-1)+(float) n/(n+1);
	}
}
int main()
{
	int n;
	cout<<"nhap gia tri cua n: ";
	cin>>n;
	cout<<"gia tri day so: "<<bai07(n);
}