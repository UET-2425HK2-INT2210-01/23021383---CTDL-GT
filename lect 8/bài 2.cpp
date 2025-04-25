#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra xem có tổ hợp con nào có tổng bằng X không
bool subsetSum(vector<int>& a, int x, int n) {
    // Tạo bảng động dp[n+1][x+1], dp[i][j] = true nếu có thể tạo tổng j từ i phần tử đầu tiên
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));

    // Tổng bằng 0 thì luôn đạt được (không chọn gì cả)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Duyệt từng phần tử trong mảng
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j < a[i - 1]) {
                // Nếu tổng j nhỏ hơn phần tử hiện tại thì không thể chọn phần tử đó
                dp[i][j] = dp[i - 1][j];
            } else {
                // Nếu có thể không chọn hoặc chọn phần tử này (kiểm tra cả 2 khả năng)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }

    // Kết quả là có tạo được tổng x từ n phần tử không
    return dp[n][x];
}

int main() {
    int n, x;
    cin >> n >> x; // Nhập số phần tử và tổng cần tìm

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Nhập các độ tuổi
    }

    // Gọi hàm kiểm tra và in kết quả
    cout << (subsetSum(a, x, n) ? "YES" : "NO");

    return 0;
}
