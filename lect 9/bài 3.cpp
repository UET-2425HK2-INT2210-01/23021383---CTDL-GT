#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // nhập số lượng vật và tổng trọng lượng tối đa

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i]; // nhập trọng lượng và giá trị của từng vật
    }

    // dp[j] lưu giá trị lớn nhất có thể đạt được với tổng trọng lượng đúng bằng j
    vector<int> dp(X + 1, 0);

    // Duyệt từng vật
    for (int i = 0; i < n; i++) {
        // Duyệt ngược để đảm bảo mỗi vật chỉ được chọn một lần
        for (int j = X; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    // In ra giá trị lớn nhất có thể đạt được với tổng trọng lượng X
    cout << dp[X] << endl;
    return 0;
}
