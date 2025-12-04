#include<iostream>
using namespace std;
void chen(int x[], int n){
	for(int i=1; i<n; i++){
		int t=x[i];
		int j=i-1;
		while(j>=0&&t<x[j]){
			x[j+1]=x[j];
			j=j-1;
		}
		x[j+1]=t;
	}
}
void chon(int x[], int n){
	for(int i=0; i<n;i++){
		int m=i;
		for(int j=i+1;j<n;j++){
			if(x[j]<x[m])
			{
				m=j;
			}
		}
		if(m!=i){
			int tg=x[i];
			x[i]=x[m];
			x[m]=tg;
		}
	}
}
void noibot(int x[], int n){
	for(int i=0; i<n;i++){
		for(int j=n-1; j>i;j--){
			if(x[j]<x[j-1])
			{
				int tg=x[j];
				x[j]=x[j-1];
				x[j-1]=tg;
			}
		}
	}
}
int main(){
	int x[]={4,5,3,2,1,0};
	int n=6;
	noibot(x,n);
	cout<<"ket qua noi bot:  ";
	for(int i=0; i<n;i++)
	{
		cout<<x[i]<<", ";
	}
	cout<<endl;
		chen(x,n);
	cout<<"ket qua chen :  ";
	for(int i=0; i<n;i++)
	{
		cout<<x[i]<<", ";
	}
	cout<<endl;
		chon(x,n);
	cout<<"ket qua chon :  ";
	for(int i=0; i<n;i++)
	{
		cout<<x[i]<<", ";
	}
	cout<<endl;
	
}