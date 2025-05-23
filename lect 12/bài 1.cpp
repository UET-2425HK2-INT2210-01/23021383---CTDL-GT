#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

// Hàm thực hiện sắp xếp topo
vector<int> topologicalSort(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1);         // Danh sách kề, chỉ số từ 1
    vector<int> inDegree(n + 1, 0);           // Mảng lưu bậc vào của các đỉnh

    // Duyệt qua các cạnh để xây dựng đồ thị và tính bậc vào
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);                // u → v
        inDegree[v]++;                        // Tăng bậc vào của v
    }

    queue<int> q;                             // Hàng đợi lưu các đỉnh có bậc vào = 0
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);                        // Đỉnh không phụ thuộc ai → cho vào queue
        }
    }

    vector<int> result;                       // Kết quả lưu thứ tự sắp xếp topo

    while (!q.empty()) {
        int u = q.front();                    // Lấy đỉnh đầu hàng đợi
        q.pop();
        result.push_back(u);                  // Thêm vào kết quả

        // Duyệt các đỉnh kề u và giảm bậc vào của chúng
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);                    // Nếu đỉnh v không còn phụ thuộc → thêm vào queue
            }
        }
    }

    return result;
}

int main() {
    ifstream infile("jobs.txt");              // Mở file đầu vào
    ofstream outfile("jobs.out");             // Mở file đầu ra

    int n, m;
    infile >> n >> m;                         // Đọc số đỉnh và số cạnh

    vector<pair<int, int>> edges;             // Danh sách cạnh (u → v)
    for (int i = 0; i < m; ++i) {
        int u, v;
        infile >> u >> v;
        edges.emplace_back(u, v);             // Thêm cạnh vào danh sách
    }

    vector<int> sortedJobs = topologicalSort(n, edges); // Gọi hàm sắp xếp topo

    for (int i = 0; i < sortedJobs.size(); ++i) {
        if (i > 0) outfile << " ";            // In cách giữa các số
        outfile << sortedJobs[i];             // In đỉnh theo thứ tự sắp xếp topo
    }

    infile.close();
    outfile.close();

    return 0;
}
