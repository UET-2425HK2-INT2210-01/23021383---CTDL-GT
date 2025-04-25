#include <bits/stdc++.h>
using namespace std;

// Hàm giải bài toán Balo 0/1 bằng lập trình động
int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    // dp[i][w] lưu giá trị lớn nhất có thể đạt được với i vật đầu tiên và trọng lượng w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Duyệt từng vật (từ 1 đến n)
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                // Nếu có thể chọn vật i (trọng lượng vật <= w)
                // Chọn max giữa không lấy (dp[i-1][w]) hoặc lấy (val + dp[i-1][w - wt])
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                // Nếu không thể chọn, giữ nguyên giá trị từ bước trước
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Kết quả là giá trị lớn nhất có thể đạt được với n vật và trọng lượng tối đa W
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W; // Nhập số vật và trọng lượng tối đa balo

    vector<int> wt(n), val(n); // Danh sách trọng lượng và giá trị các vật
    for (int i = 0; i < n; ++i) {
        cin >> wt[i] >> val[i]; // Nhập từng cặp trọng lượng và giá trị
    }

    // Gọi hàm balo và in ra kết quả
    cout << knapsack(n, W, wt, val);

    return 0;
}
