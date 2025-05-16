#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = 1e9; // Giá trị vô cực đại diện cho "không có đường đi"

int main() {
    ifstream fin("dirty.txt");    // Mở file input để đọc dữ liệu
    ofstream fout("dirty.out");   // Mở file output để ghi kết quả

    int n, m, s, e;
    fin >> n >> m >> s >> e; // Đọc số thành phố, số đường, điểm bắt đầu s và điểm kết thúc e

    vector<tuple<int, int, int>> edges; // Danh sách các cạnh: (u, v, d)
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF)); // Ma trận khoảng cách cho Floyd-Warshall
    vector<int> parent(n + 1, -1); // Lưu cha của mỗi đỉnh để truy vết đường đi từ s đến e

    // Đọc m cạnh, mỗi cạnh là: u, v, d
    for (int i = 0; i < m; i++) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.emplace_back(u, v, d);   // Thêm cạnh vào danh sách cho Bellman-Ford
        dist[u][v] = d;                // Gán độ bẩn ban đầu cho Floyd-Warshall
    }

    // ----------------- PHẦN A: Bellman-Ford từ s đến e -----------------

    vector<int> d(n + 1, INF); // d[v] là độ bẩn nhỏ nhất từ s đến v
    d[s] = 0; // Khởi tạo: s đến s là 0

    // Lặp n-1 lần để cập nhật độ bẩn tối thiểu
    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;    // Cập nhật độ bẩn nhỏ hơn
                parent[v] = u;      // Ghi nhớ cha của v là u
            }
        }
    }

    // Ghi kết quả độ bẩn nhỏ nhất từ s đến e
    if (d[e] == INF) {
        fout << "INF" << endl;          // Nếu không có đường đi
        fout << "No path" << endl;      // Không in đường đi
    } else {
        fout << d[e] << endl;           // In tổng độ bẩn nhỏ nhất

        // Truy vết đường đi từ e → s thông qua mảng parent[]
        vector<int> path;
        for (int v = e; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end()); // Đảo ngược để có s → e

        // In đường đi (dãy thành phố)
        for (int i = 0; i < path.size(); i++) {
            fout << path[i];
            if (i < path.size() - 1) fout << " ";
        }
        fout << endl;
    }

    // ----------------- PHẦN B: Floyd-Warshall cho mọi cặp -----------------

    // Đặt khoảng cách từ i đến i là 0
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    // Ba vòng lặp Floyd-Warshall để cập nhật đường đi ngắn nhất
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Ghi ma trận khoảng cách ngắn nhất cho mọi cặp đỉnh
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) fout << "INF"; // Nếu không có đường đi
            else fout << dist[i][j];              // In khoảng cách
            if (j < n) fout << " ";               // Cách nhau bằng dấu cách
        }
        fout << endl; // Xuống dòng mỗi hàng
    }

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
