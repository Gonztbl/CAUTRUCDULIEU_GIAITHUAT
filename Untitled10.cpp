//### Bài 10: Tính T= x^n
#include<iostream>
#include<cmath>
using namespace std;
//bai toan yeu cau nhap 2 gia tri vi vay can phai su dung dieu kien
//trong truong hop x>0 x<0 x=1 n=-1 n=0
// xet cac dieu kien nhu trem thi
int bai10(int x,int n)
{ 
	if(n==1)
	{
		return x;
	}
	if(n==-1)
	{
		return 1/x;
	}
	if(n<0)
	{
		return bai10(x,n-1)* (1/x);
		//neu nhu n be hon 0 , dau tien n=-1 thi se cho ra ket qua la 1/x tuong tu nhu the thi khi be hon 0 thi se *1/n
	}
	else{
		if(n==0)
		{return 1;
		}
		else
	{	return bai10(x,n-1)*pow(x,1);
	}
	}

}
int main()
{   int x,n;
	cout<<"nhap gia tri cua x: ";
	cin>>x;
	cout<<"nhap gia tri n: ";
	cin>>n;
		cout<<endl;
	cout<<"gia tri cua bai10 la: "<<bai10(x,n);
	return 0;
}