#include<bits/stdc++.h>
using namespace std;
struct thisinh{
	int sbd;
	char hoten[50];
	int diem;
};
struct node{
	thisinh infor;
	node*next;
};
typedef node*tro;
void nhapds(tro &L, thisinh&x)
{
	int i=0;
	tro P,Q;
	L=NULL;
	do{
		cout<<"nhap thong tin sinh vien thu "<<i<<endl;
		cout<<"nhap so bao danh: "; cin>>x.sbd;
		cout<<"nhap ho ten: "; fflush(stdin); gets(x.hoten);
		cout<<"nhap diem: "; cin>>x.diem;
		
		P=new node;
		P->infor=x;
		P->next=NULL;
				if(L == NULL) {
				L = P;
				Q=P;}
		else {
		Q->next = P;
		Q = P;
		}
		i++;
	
		
	}
	while(i<2);

	
}
 void hienthi(tro&L){
 	tro Q=L;
 	cout<<"so bao danh "<<setw(15)<<"hoten"<<setw(50)<<"diem"<<endl;
 	while(Q!=NULL){
 		cout<<Q->infor.sbd<<setw(15)<<Q->infor.hoten<<setw(50)<<Q->infor.diem<<endl;
 		Q= Q->next;
	 }
 }
int main(){
	tro L;
	thisinh x;
	nhapds(L,x);
	hienthi(L);
}
