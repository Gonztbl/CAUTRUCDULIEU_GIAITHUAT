#include <iostream>
using namespace std;

// Hàm tìm kiếm nhị phân
int BinarySearch(int a[], int b, int low, int high) {
    if (low > high) {
        return -1; // Không tìm thấy
    }
    int mid = (low + high) / 2;
    
    if (a[mid] == b) {
        return mid; // Tìm thấy giá trị tại vị trí mid
    } else if (b < a[mid]) {
        return BinarySearch(a, b, low, mid - 1); // Tìm ở nửa trái
    } else {
        return BinarySearch(a, b, mid + 1, high); // Tìm ở nửa phải
    }
}
int main() {
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17}; // Mảng đã sắp xếp
    int n = sizeof(a) / sizeof(a[0]); // Kích thước mảng
    int key = 7; // Giá trị cần tìm
    int result = BinarySearch(a, key, 0, n - 1);
	//hien thi ra man hinh
	cout<<"--------------ket qua-------------- ";
	cout<<"\n";
    if (result != -1) {
        cout << "Found " << key << " at index " << result << endl;
    } else {
        cout << "Not found!" << endl;
    }
    return 0;
}
