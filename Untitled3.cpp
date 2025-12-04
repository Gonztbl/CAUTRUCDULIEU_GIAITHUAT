//bai3
//tinh tong 1+1/2+1/3+...+1/n
#include<iostream>
using namespace std;
//can phai su dung kieu float
float bai03(int n)
{
	if(n==1)
	{
		return 1;
	}
	else 
	{
		return bai03(n-1)+(float)1/n;
		//can phai ép kiểu du lieu la float neu nhu k ep kieu float thi se tinh sai cac gia tri
	}
}
int main(){
	int n;
	cout<<"nhap n: ";
	cin>>n;
	cout<<"gia tri cua S(n)= "<<bai03(n);
}