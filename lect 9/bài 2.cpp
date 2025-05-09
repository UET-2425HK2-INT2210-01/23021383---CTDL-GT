#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // nhập số phần tử n và tổng cần kiểm tra X

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i]; // nhập mảng A gồm n phần tử
    }

    // Khởi tạo bảng dp: dp[i][j] = true nếu có thể tạo tổng j từ i phần tử đầu tiên
    vector<vector<bool>> dp(n + 1, vector<bool>(X + 1, false));

    // Với tổng bằng 0 thì luôn đúng (tập con rỗng luôn tạo được tổng 0)
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // Duyệt qua từng phần tử và từng tổng có thể tạo ra
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= X; ++j) {
            if (j < A[i - 1]) {
                dp[i][j] = dp[i - 1][j]; // không chọn phần tử thứ i
            } else {
                // chọn hoặc không chọn phần tử thứ i để tạo tổng j
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            }
        }
    }

    // In kết quả cuối cùng: có thể tạo tổng X hay không
    if (dp[n][X])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
