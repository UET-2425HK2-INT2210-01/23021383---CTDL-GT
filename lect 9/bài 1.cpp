#include <iostream>
#include <vector>
#include <iomanip> // để định dạng số thực với setprecision

using namespace std;

// Hàm phân hoạch cho thuật toán QuickSort
int partition(vector<double>& arr, int low, int high) {
    double pivot = arr[high]; // chọn phần tử cuối cùng làm pivot
    int i = low - 1; // chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        // nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // hoán đổi để đưa phần tử nhỏ hơn về trước pivot
        }
    }
    swap(arr[i + 1], arr[high]); // đưa pivot về đúng vị trí
    return i + 1; // trả về chỉ số của pivot sau phân hoạch
}

// Hàm đệ quy QuickSort
void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // tìm vị trí phân hoạch
        quickSort(arr, low, pivotIndex - 1);        // sắp xếp phần bên trái
        quickSort(arr, pivotIndex + 1, high);       // sắp xếp phần bên phải
    }
}

int main() {
    int n;
    cin >> n; // nhập số lượng phần tử

    vector<double> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i]; // nhập từng phần tử
    }

    quickSort(numbers, 0, n - 1); // gọi hàm sắp xếp QuickSort

    // in kết quả sau khi sắp xếp với độ chính xác 6 chữ số thập phân
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << numbers[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
