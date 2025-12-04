//bai 1 
#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;

class xehoi{
	private:
		char chu[30];
		char bienso[15];
		char hangsx[39];
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend class congdan;
};
class congdan{
	private:
		char socmnd[20];
		char hovaten[30];
		int d,m,y;
		char hokhau[30];
	public: 
	    void nhap();
	    void xuat();
	    friend class phieu;
	    friend class xehoi;
		};
class phieu{
	private:
	congdan x[50];
	xehoi y[50];
	int n;
	public:
		void nhap();
		void xuat();
		friend class congdan;
		friend class xehoi;
};
void xehoi::nhap(){
	cout<<"\n --------------NHAP THONG TIN XE------------"<<endl;
	cout<<"\n Ten chu xe: "; fflush(stdin); gets(chu);
	cout<<"\n Bien so xe: "; fflush(stdin); gets(bienso);
	cout<<"\n Hang san xuat xe: "; fflush(stdin); gets(hangsx);
	
}
void xehoi::xuat(){
	cout<<setw(5)<<chu<<setw(20)<<bienso<<setw(20)<<hangsx<<endl;
}
void congdan::nhap(){
	cout<<"\n --------------NHAP THONG TIN CHU XE ------------"<<endl;
	cout<<"\n So chung minh nhan dan: "; fflush(stdin); gets(socmnd);
	cout<<"\n Ho va ten: "; fflush(stdin); gets(hovaten);
	cout<<"\n Ngay sinh: "; cin>>d;
	cout<<"\n Thang sinh: "; cin>>m;
	cout<<"\n Nam sinh: "; cin>>y;
	cout<<"\n Ho khau thuong tru: "; fflush(stdin); gets(hokhau);
}

void congdan::xuat(){
	cout<<"\n So cmnd: "<<socmnd;
	cout<<"\n Ho va ten: "<<hovaten;
	cout<<"\n Ngay sinh: "<<d<<"/"<<m<<"/"<<y<<endl;
	cout<<"\n Ho khau thuong tru: "<<hokhau<<endl;
	
}
void phieu::nhap(){
	cout<<"\n ----------------NHAP THONG TIN PHIEU ----------"<<endl;
	cout<<"\n Nhap so luong xe hoi(1xe=1chu): "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"--------------Nhap thong tin ve xe thu "<<i+1<<"---------------"<<endl;
		x[i].nhap();
		y[i].nhap();
	}
}
void phieu::xuat(){
	cout<<"\n ---------------------PHIEU QUAN LY OTO--------------"<<endl;
	cout<<"\n So luong xe oto: "<<n;
    for(int i=0; i<n; i++){
    	cout<<"\n -------THONG TIN--------- "<<endl;
    	x[i].xuat();
    	cout<<setw(5)<<"Ten chu xe"<<setw(20)<<"Bien so"<<setw(20)<<"Ten hang sx"<<endl;
    	y[i].xuat();
	}
}

int main(){
	phieu p;
	p.nhap();
	p.xuat();
	return 0;
}
/*#include <iostream>
#include <vector>
#include <string>

class CongDan {
private:
    std::string soCMND;
    std::string hoTen;
    std::string ngaySinh;
    std::string hoKhau;

public:
    CongDan() {}
    CongDan(std::string cmnd, std::string ten, std::string ngay, std::string hokhau)
        : soCMND(cmnd), hoTen(ten), ngaySinh(ngay), hoKhau(hokhau) {}

    void nhapThongTin() {
        std::cout << "Nhap CMND: ";
        std::cin >> soCMND;
        std::cout << "Nhap ho ten: ";
        std::cin.ignore();  // Xóa b? nh? ð?m
        std::getline(std::cin, hoTen);
        std::cout << "Nhap ngay sinh: ";
        std::cin >> ngaySinh;
        std::cout << "Nhap ho khau thuong tru: ";
        std::cin.ignore();
        std::getline(std::cin, hoKhau);
    }

    void xuatThongTin() const {
        std::cout << "CMND: " << soCMND << "\nHo ten: " << hoTen << "\nNgay sinh: " << ngaySinh
                  << "\nHo khau thuong tru: " << hoKhau << std::endl;
    }

    std::string getSoCMND() const {
        return soCMND;
    }

    int getNamSinh() const {
        // Gi? s? ngày sinh có ð?nh d?ng là DD/MM/YYYY
        // Trích xu?t nãm sinh t? ngày sinh
        std::string namSinhStr = ngaySinh.substr(6, 4);
        return std::stoi(namSinhStr);
    }
};

class XeHoi {
private:
    CongDan chuSoHuu;
    std::string bienSoXe;
    std::string hangSanXuat;

public:
    XeHoi() {}
    XeHoi(CongDan chu, std::string bienSo, std::string hang)
        : chuSoHuu(chu), bienSoXe(bienSo), hangSanXuat(hang) {}

    void nhapThongTin() {
        chuSoHuu.nhapThongTin();
        std::cout << "Nhap bien so xe: ";
        std::cin >> bienSoXe;
        std::cout << "Nhap hang san xuat: ";
        std::cin >> hangSanXuat;
    }

    void xuatThongTin() const {
        chuSoHuu.xuatThongTin();
        std::cout << "Bien so xe: " << bienSoXe << "\nHang san xuat: " << hangSanXuat << std::endl;
    }

    std::string getChuSoHuuCMND() const {
        return chuSoHuu.getSoCMND();
    }

    int getChuSoHuuNamSinh() const {
        return chuSoHuu.getNamSinh();
    }

    std::string getHangSanXuat() const {
        return hangSanXuat;
    }
};

void hienThiDanhSach(const std::vector<XeHoi>& danhSachXe) {
    std::cout << "Danh sach xe hoi:\n";
    for (const auto& xe : danhSachXe) {
        xe.xuatThongTin();
        std::cout << "---------------------\n";
    }
}

void chenXeHoi(std::vector<XeHoi>& danhSachXe, int viTriChen) {
    XeHoi xeMoi;
    std::cout << "Nhap thong tin cho xe hoi can chen:\n";
    xeMoi.nhapThongTin();

    if (viTriChen >= 0 && viTriChen <= danhSachXe.size()) {
        danhSachXe.insert(danhSachXe.begin() + viTriChen, xeMoi);
        std::cout << "Da chen xe hoi thanh cong!\n";
    } else {
        std::cerr << "Vi tri chen khong hop le.\n";
    }
}

void hienThiXeHondaNam1985(const std::vector<XeHoi>& danhSachXe) {
    std::cout << "Danh sach xe Honda co chu so huu sinh nam 1985:\n";
    for (const auto& xe : danhSachXe) {
        if (xe.getHangSanXuat() == "Honda" && xe.getChuSoHuuNamSinh() == 1985) {
            xe.xuatThongTin();
            std::cout << "---------------------\n";
        }
    }
}

int main() {
    int n;
    std::cout << "Nhap so luong xe hoi: ";
    std::cin >> n;

    std::vector<XeHoi> danhSachXe;

    for (int i = 0; i < n; ++i) {
        XeHoi xe;
        std::cout << "Nhap thong tin cho xe hoi thu " << i + 1 << ":\n";
        xe.nhapThongTin();
        danhSachXe.push_back(xe);
    }

    // Hi?n th? danh sách v?a nh?p
    hienThiDanhSach(danhSachXe);

    // Chèn thêm m?t xe hoi m?i vào v? trí th? k
    int viTriChen;
    std::cout << "Nhap vi tri can chen them xe hoi: ";
    std::cin >> viTriChen;
    chenXeHoi(danhSachXe, viTriChen);

    // Hi?n th? danh sách sau khi chèn
    hienThiDanhSach(danhSachXe);

    // Hi?n th? danh sách xe Honda có ch? s? h?u sinh nãm 1985
    hienThiXeHondaNam1985(danhSachXe);

    return 0;
}
*/