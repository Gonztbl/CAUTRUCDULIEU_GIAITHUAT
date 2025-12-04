#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class gianhang;
class hop;
class hang;

class hang {
protected:
    char mapt[30];
    char loai[30];
    char namsx[10];
    char hangsx[30];

public:
    void nhap();
    void xuat();
};

class hop : public hang {
private:
    char kieudang[30];
    char chatlieu[30];
    char ghichu[30];
    float thetich;

public:
    void nhap();
    void xuat();
    friend class gianhang;
    friend void xapxep(gianhang& gh, int n);
};

class gianhang {
private:
    char magh[30];
    char tengh[30];
    float dientich;
    int n;
    hop x[50];

public:
    void nhap();
    void xuat();
    friend void sua(gianhang& gh);
    friend void xapxep(gianhang& gh, int n);
};

void hang::nhap() {
    cout << "\n ---------Nhap thong tin hang-----------" << endl;
    cout << "\n Nhap Ma pt: ";
    fflush(stdin);
    gets(mapt);
    cout << "\n Nhap Loai Hang: ";
    fflush(stdin);
    gets(loai);
    cout << "\n Nhap Nam sx: ";
    fflush(stdin);
    gets(namsx);
    cout << "\n Nhap Hangx sx: ";
    fflush(stdin);
    gets(hangsx);
}

void hang::xuat() {
    cout << setw(15) << mapt << setw(15) << loai << setw(15) << namsx << setw(15) << hangsx;
}

void hop::nhap() {
    hang::nhap();
    cout << "\n --------Nhap thong tin Hop------" << endl;
    cout << "\n Nhap kieu dang: ";
    fflush(stdin);
    gets(kieudang);
    cout << "\n Nhap chat lieu: ";
    fflush(stdin);
    gets(chatlieu);
    cout << "\n Nhapp the tich hop: ";
    cin >> thetich;
    cout << "\n Nhap ghi chu: ";
    fflush(stdin);
    gets(ghichu);
}

void hop::xuat() {
    hang::xuat();
    cout << setw(5) << "|" << kieudang << "|" << setw(5) << "|" << chatlieu << "|" << setw(5) << "|" << thetich << "|" << setw(5) << "|" << ghichu << endl;
}

void gianhang::nhap() {
    cout << "\n-----------Nhap thong tin gian hang-----------" << endl;
    cout << "\n Nhap ma gian hang: ";
    fflush(stdin);
    gets(magh);
    cout << "\n Nhap ten gian hang: ";
    fflush(stdin);
    gets(tengh);
    cout << "\n Nhap dien tich gian hang: ";
    cin >> dientich;
    cout << "\n Nhap so luong hop trong gian hang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\n Nhap thong tin cua hop thu: " << i + 1 << endl;
        x[i].nhap();
    }
}

void gianhang::xuat() {
    cout << setw(5) << "Ma GH: " << magh << setw(30) << "Ten GH: " << tengh << endl;
    cout << setw(5) << "Dien tich gian hang: " << dientich << setw(30) << "So luong hop: " << n << endl;
    cout << setw(5) << "Ma pt" << setw(5) << "Loai" << setw(5) << "Nam sx" << setw(5) << "Hang sx" << setw(5) << "|Kieu Dang| " << setw(5) << "|Chat lieu| " << setw(5) << "|The tich| " << setw(5) << "|Ghi chu " << endl;
    for (int i = 0; i < n; i++) {
        x[i].xuat();
    }
}

void sua(gianhang& gh) {
    strcpy(gh.tengh, "Do Nhua");
}

void xapxep(gianhang& gh, int n) {
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gh.x[i].thetich < gh.x[j].thetich) {
                hop tg = gh.x[i];
                gh.x[i] = gh.x[j];
                gh.x[j] = tg;
            }
        }
    }
}

int main() {
    gianhang gh;
    int n;
    gh.nhap();
    gh.xuat();
    sua(gh);
    cout << "\n --------------Thong tin sau khi sua-------------" << endl;
    gh.xuat();
    xapxep(gh, n);
    cout << "\n---------------Thong tin sau khi sap xep----------" << endl;

    return 0;
}
