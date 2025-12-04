#include<iostream>
#include<fstream>
using namespace std;
class mang{
	private:
		int n;
        float value[50];
	public: 
//	phuong thuc toan tu
	mang operator++(); //1 ngoi	
	//toan tu nap chong tang 1 don vi
	mang operator--(); //1 ngoi
	//toan tu nap chong giam 1 don vi
	friend istream operator>>(istream&in, mang& a);
	//ham ban de nhap 
	friend ostream operator<<(ostream&out, mang a);
	//ham ban de xuat	
};
mang mang::operator++(){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(value[i]>value[j])
			{
				//cap bien trung gian de so sanh theo thu tu tang dan
				float tg=value[i];
				value[j]=value[i];
				tg=value[j];
			}
		}
	}
}
mang mang::operator--(){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(value[i]<value[j])
			{
				//cap bien trung gian de so sanh theo thu tu tang dan
				float tg=value[i];
				value[j]=value[i];
				tg=value[j];
			}
		}
	}
}
istream operator>>(istream&in, mang& a){
	cout<<"\n Nhap so luong phan tu cua mang:"; 
	in>>a.n;
	cout<<"\n Nhap cac gia tri cua mang: "<<endl;
	for(int i=0; i < a.n; i++){
	cout<<"value["<<i<<"]";
	in>>a.value[i]<<"\t";
	}
	return in;
}
ostream operator<<(ostream&out, mang a){
	
  for (int i = 0; i < a.n; i++)
  {
  out<< a.value[i] << "\t";
  }

  return out;

}
int main(){
	mang a;
  cout << "Nhap mang a: " << endl;
  cin >> a;
  ofstream ofs("MANG.txt");
  cout << "Mang a vua nhap: " << endl;
  cout << a << endl;
  ofs << "Mang a vua nhap: " << endl;
  ofs << a << endl;
  ++a;
  cout << "Mang a sx tang dan: " << endl;
  cout << a << endl;
  ofs << "Mang a sx tang dan: " << endl;
  ofs << a << endl;
  --a;
  cout << "Mang a sx giam dan: " << endl;
  cout << a << endl;
  ofs << "Mang a sx giam dan: " << endl;
  ofs << a << endl;
  return 0;
}
