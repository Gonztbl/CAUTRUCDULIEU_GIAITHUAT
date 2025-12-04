//Bài 08: Tính tổng S(n)= 1/2+ 3/4+ 5/6+...+2n+1/2n+2
#include<iostream>
using namespace std;
float bai08(int n)
{

if(n==0)
{
	return (float) 1/2;}
else 
{
	return bai08(n-1)+ (float) (2*n+1)/(2*n+2);
}
}
int main()
{
	int n;
	cout<<"nhap n: ";
	cin>>n;
	bai08(n);
	cout<<"gia tri cua bai toan: "<<bai08(n);
}