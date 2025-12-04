#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>

using namespace std;
using namespace chrono;

// Hàm nhân ma trận tuần tự
vector<vector<double>> multiplyMatrices(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int n = a.size();
    vector<vector<double>> c(n, vector<double>(n, 0.0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

// Hàm nhân ma trận song song với OpenMP (cải tiến)
vector<vector<double>> multiplyMatricesOMP(const vector<vector<double>>& a, const vector<vector<double>>& b) {
    int n = a.size();
    vector<vector<double>> c(n, vector<double>(n, 0.0));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main() {
    int n = 1000; // Kích thước ma trận
    vector<vector<double>> a(n, vector<double>(n, 1.0)); // Ma trận a với giá trị 1.0
    vector<vector<double>> b(n, vector<double>(n, 1.0)); // Ma trận b với giá trị 2.0

    // Thực hiện phép nhân ma trận song song (OpenMP)
    auto start = high_resolution_clock::now();
    vector<vector<double>> c = multiplyMatricesOMP(a, b); // Sử dụng hàm cải tiến
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Thoi gian chay open mp " << duration.count() << " milliseconds" << endl;

    // Thực hiện phép nhân ma trận tuần tự để so sánh
    start = high_resolution_clock::now();
    vector<vector<double>> c_seq = multiplyMatrices(a, b); // Sử dụng hàm tuần tự
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Thoi gian chay tuan tu " << duration.count() << " milliseconds" << endl;

    return 0;
}
