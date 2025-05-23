#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc cạnh: gồm 2 đỉnh u, v và trọng số d
struct Edge {
    int u, v, d;
};

// Lớp Union-Find để kiểm tra chu trình
class UnionFind {
    vector<int> parent, rank;
public:
    // Khởi tạo: mỗi đỉnh là cha của chính nó
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    // Tìm gốc của một đỉnh (kèm nén đường)
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    // Hợp nhất hai tập hợp, trả về true nếu thành công
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        // Hợp nhất theo rank
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            if (rank[rootU] == rank[rootV]) {
                rank[rootV]++;
            }
        }
        return true;
    }
};

// Hàm thực hiện thuật toán Kruskal
vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.d < b.d;
    });

    UnionFind uf(n);           // Khởi tạo Union-Find
    vector<Edge> mst;          // Lưu cây khung nhỏ nhất
    int totalCost = 0;

    // Duyệt các cạnh theo thứ tự tăng dần trọng số
    for (const Edge& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mst.push_back(edge);    // Thêm cạnh vào cây khung
            totalCost += edge.d;
        }
    }

    return mst;
}

int main() {
    ifstream infile("connection.txt");     // Mở file đầu vào
    ofstream outfile("connection.out");    // Mở file đầu ra

    int n, m;
    infile >> n >> m;                      // Đọc số đỉnh và số cạnh

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        infile >> u >> v >> d;
        edges.push_back({u, v, d});        // Thêm cạnh vào danh sách
    }

    vector<Edge> mst = kruskalMST(n, edges);  // Tìm cây khung nhỏ nhất

    // Tính tổng chi phí
    int totalCost = 0;
    for (const Edge& edge : mst) {
        totalCost += edge.d;
    }

    // Ghi kết quả ra file
    outfile << totalCost << endl;
    for (const Edge& edge : mst) {
        outfile << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
