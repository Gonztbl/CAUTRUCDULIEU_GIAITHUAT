//Bài 05: Tính tổng S(n)= 1+ 1/3+ 1/5+...+1/(2n+1)
#include<iostream>
using namespace std;
float bai05(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{return bai05(n-1)+(float)1/(2*n+1);
	}
}
int main()
{
	int n;
	cout<<"nhap n: ";
	cin>>n;
	cout<<"gia tri cua day so la: "<<bai05(n);
}