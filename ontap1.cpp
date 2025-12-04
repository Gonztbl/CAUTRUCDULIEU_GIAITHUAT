#include<bits/stdc++.h>
using namespace std;
struct sinhvien{
	int namsinh;
};
struct Node{
	sinhvien infor;
	Node*next;
};
typedef Node*tro;
void nhapsv(sinhvien &sv){
	cout<<"nhap nam sinh: "; cin>>sv.namsinh;
}
void nhapds(tro &L, int sl){
	sinhvien X;
	tro P,Q;
	L=NULL;
	for(int i=0; i<sl;i++){
		nhapsv(X);
		P=new Node;
		P->infor=X;
		P->next=NULL;
		if(L==NULL){
			L=P;
			Q=P;
		}
		else{
			Q->next=P;
			Q=P;
		}
	}
}
void hiends(tro&L){
	cout<<"nam sinh: "<<endl;
	if(L==NULL){
		cout<<"ds rong";
		return;
	}
	tro Q=L;
	while(Q!=NULL){
		sinhvien X=Q->infor;
		cout<<X.namsinh<<endl;
		Q=Q->next;
	}
}
void xoaptdautien(tro &L){
	if(L==NULL){
		cout<<"loi ";
		return;
	}
	tro Q=L;
	L=L->next;
	delete Q;
	
}
void xoa(tro &L,int b,int sl){
	tro m = L;
	if(L == NULL){
		cout<<"danh sach rong"<<endl;
	}else{

		if(b == 0){
			tro u = L;
			L = L->next;
			delete u;
		}else if(b == sl-1){
			while(m->next->next == NULL){
				tro c = m->next;
				m->next
				 = NULL;
				delete c;
			}
		}
		else{
			for(int i=0; i<b-1; i++){
				m=m->next;
			}
			tro z = m->next;
			m->next = z->next;
			delete z;
		}
	}
}
void chenvtrk(tro L, int vt){
	tro M,Q=L;
	int d=0;
	while(Q!=NULL && d<vt){
		M=Q;
		Q=Q->next;
		d++;
		
	}
	if(Q==NULL){
		cout<<"loi";
		return;
	}
	tro P=new Node;
	P->infor.namsinh=2004;
	P->next=M->next;
	M->next=P;
}
void sapxep(tro&L){float tmp;
	for(tro j =L; j!= NULL; j=j->next){
		for(tro z = j->next; z!= NULL; z=z->next){
			if(z->infor.namsinh < j->infor.namsinh){
			tmp=z->infor.namsinh;
				z->infor.namsinh = j->infor.namsinh;
				j->infor.namsinh = tmp;
			}
		}
	}
}
void tim(tro &L){tro t =L;
	if(t == NULL){
		cout<<"danh sach rong"<<endl;
	}else{
		for( t = L; t!= NULL; t=t->next){
		if(t->infor.namsinh >= 6){
		cout<<t->infor.namsinh<<endl;;
		}
	}
	}
}
int main(){
	int sl;
	cout<<"nhap sl: ";
	cin>>sl;
	sinhvien sv;
	tro L;
	nhapds(L,sl);
	hiends(L);
	cout<<"xoa pt dau tien";
	xoaptdautien(L);
	hiends(L);
	int vt;
	cout<<"nhap vi tri chen: "; cin>>vt;
	chenvtrk(L,vt);
	cout<<"danh sach sau chen:";
	hiends(L);
	sapxep(L);
	cout<<"sau khi sap xep----------";
	hiends(L);
	cout<<"tim nam sinh lon hon 6"<<endl;
	tim(L);
	int b;
	cout<<"nhap vi tri can xoa: "; cin>>b;
	xoa(L,b,sl);
	hiends(L);
	
}
