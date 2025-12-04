//Bài 06: Tính tổng S(n)= 1/1*2+ 1/2*3+ 1/3*4+ ...+ 1/(n* (n+1))
#include<iostream>
using namespace std;
float bai06(float n)
{
	if(n==1)
	{
	return (float)1/2;
	}
	else 
	{
		return (float)bai06(n-1)+ (float) 1/(n*(n+1));
	}
}
int main()
{
	float n;
	cout<<"nhap n: ";
	cin>>n;
	bai06(n);
	cout<<"gia tri cua day so: "<<bai06(n);
	return 0;
}