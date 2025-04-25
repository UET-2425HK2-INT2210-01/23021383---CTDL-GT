#include <bits/stdc++.h>
using namespace std;

// Hàm sắp xếp nhanh (Quick Sort)
void quickSort(vector<double>& arr, int low, int high) {
    if (low >= high) return; // Nếu mảng con có 0 hoặc 1 phần tử thì không cần sắp

    double pivot = arr[low]; // Chọn phần tử đầu tiên làm chốt
    int i = low + 1;         // i sẽ quét từ trái qua
    int j = high;            // j sẽ quét từ phải sang

    while (i <= j) {
        // Tìm phần tử bên trái lớn hơn pivot
        while (i <= high && arr[i] <= pivot) i++;

        // Tìm phần tử bên phải nhỏ hơn hoặc bằng pivot
        while (j > low && arr[j] > pivot) j--;

        // Nếu i và j chưa giao nhau, hoán đổi phần tử ở i và j
        if (i < j) swap(arr[i], arr[j]);
    }

    // Đưa pivot vào vị trí chính xác (tức là giữa 2 phần: nhỏ hơn và lớn hơn)
    swap(arr[low], arr[j]);

    // Đệ quy sắp xếp 2 nửa còn lại
    quickSort(arr, low, j - 1);   // Nửa bên trái pivot
    quickSort(arr, j + 1, high); // Nửa bên phải pivot
}

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử

    vector<double> arr(n); // Khai báo mảng chứa số thực
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Nhập từng phần tử
    }

    // Gọi hàm sắp xếp nhanh
    quickSort(arr, 0, n - 1);

    // In ra mảng đã sắp xếp
    for (double x : arr) {
        cout << x << " ";
    }

    return 0;
}
