#include<iostream>
#define Max 20
using namespace std;
typedef struct{
	int A[Max][Max];
	int n;
}Graph;
//ham nhap
void init_Graph(Graph*G,int n){
	int i,j;

		for(i=1;i<=G->n;i++){
		for(j=1; j<=G->n;j++){
			G->A[i][j]=0;
		}
	}
}
//ham them khung
int add_edge(Graph *G, int x, int y){
	return G->A[x][y]=1;
}
int kiemtrake(Graph *G,int x,int y){
	return(G->A[x][y]!=0);
}
int main(){
	//khoi tao do thi
	Graph G;
	int i,j;
	cout<<"nhap n: ";
	cin>>G.n;
	cout<<"\n";
	init_Graph(&G,G.n);
	//nhap thong tin duoi dang cung:
	add_edge(&G,1,2);
	add_edge(&G,1,1);
	//nhap thong tin duoi dang matran:
	//hien thi
	cout<<"so dinh cua do thi: "<<G.n<<"\n";

	for(i=1;i<=G.n;i++){
		for(j=1;j<=G.n;j++){
			cout<<G.A[i][j]<<" ";
			
		}
		cout<<"\n";
	}
	return 0;
}