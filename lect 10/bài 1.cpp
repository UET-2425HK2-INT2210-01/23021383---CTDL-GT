#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000; // Giả sử tối đa 100000 đỉnh
vector<int> graph[MAX]; // Danh sách kề 
bool visited[MAX];      // Mảng đánh dấu các đỉnh đã được thăm

// Hàm duyệt DFS
void dfs(int u) {
    visited[u] = true; // Đánh dấu đã thăm đỉnh u
    for (int v : graph[u]) { // Duyệt tất cả đỉnh kề với u
        if (!visited[v]) {   // Nếu đỉnh v chưa được thăm
            dfs(v);          // Gọi đệ quy DFS cho v
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    // Nhập các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y; // Nhập 2 đỉnh của một cạnh
        graph[x].push_back(y); // Thêm y vào danh sách kề của x
        graph[y].push_back(x); // Đồ thị vô hướng nên cũng thêm x vào danh sách kề của y
    }

    int count = 0; // Biến đếm số thành phần liên thông

    // Duyệt tất cả các đỉnh từ 1 đến n
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // Nếu đỉnh i chưa được thăm
            dfs(i);        // Gọi DFS từ đỉnh i
            count++;       // Mỗi lần gọi DFS là phát hiện thêm 1 thành phần liên thông
        }
    }

    // In ra kết quả
    cout << count << endl;

    return 0;
}
