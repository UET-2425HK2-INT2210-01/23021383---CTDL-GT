#include <iostream>
using namespace std;

void quickSort(int a[], int left, int right) {
    if (left >= right) return;

    int pivot = a[(left + right) / 2]; // Chọn phần tử giữa làm pivot
    int i = left, j = right;

    while (i <= j) {
        while (a[i] < pivot) i++; // Tìm phần tử bên trái ≥ pivot
        while (a[j] > pivot) j--; // Tìm phần tử bên phải ≤ pivot
        if (i <= j) {
            swap(a[i], a[j]); // Hoán đổi nếu i ≤ j
            i++;
            j--;
        }
    }
    quickSort(a, left, j);
    quickSort(a, i, right);
}
int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1); // Gọi hàm QuickSort

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}
