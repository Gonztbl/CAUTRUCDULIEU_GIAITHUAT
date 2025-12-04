#include<iostream>
using namespace std;
int F(int n){
	if(n<1){
		return 1;
	}
	else{
		return F(n-1)+F(n-3);
	}
}
int main(){
	int n;
	cout<<"nhap n: ";
	cin>>n;
	cout<<"ket qua: "<<F(n);
}