#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100005;
vector<int> graph[MAX]; // Danh sách kề
bool visited[MAX];      // Mảng đánh dấu đã thăm
int dist[MAX];          // Mảng lưu khoảng cách ngắn nhất từ X đến mỗi đỉnh

// Hàm tìm đường đi ngắn nhất từ start đến end trong đồ thị có hướng
int shortestPath(int start, int end) {
    queue<int> q;        // Hàng đợi để duyệt BFS
    q.push(start);       // Bắt đầu từ đỉnh start
    visited[start] = true;
    dist[start] = 0;     // Khoảng cách từ start đến chính nó là 0

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;         // Đánh dấu đã thăm
                dist[v] = dist[u] + 1;     // Cập nhật khoảng cách
                q.push(v);                // Thêm vào hàng đợi để duyệt tiếp
            }
        }
    }

    if (visited[end]) return dist[end];  // Nếu đến được đỉnh end thì trả về khoảng cách
    else return -1;                      // Nếu không có đường đi thì trả về -1
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y; // Nhập số đỉnh, số cạnh và 2 đỉnh X, Y cần tìm đường đi

    // Nhập các cạnh của đồ thị có hướng
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;           // Cạnh có hướng từ u đến v
        graph[u].push_back(v);   // Chỉ thêm v vào danh sách kề của u 
    }

    // Gọi hàm tìm đường đi ngắn nhất và in ra kết quả
    int result = shortestPath(X, Y);
    cout << result << endl;

    return 0;
}
