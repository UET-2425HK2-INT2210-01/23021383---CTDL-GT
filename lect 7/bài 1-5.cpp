#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {      // ham hoan doi hai gia tri
    int temp = a;
    a = b;
    b = temp;
}

void sort(vector<int>& a) {      // ham sap xep tang dan

    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);   // hoan vi neu phan tu sau nho hon
            }
        }
    }
}

int main() {
    ifstream input("numbers.txt");              // mo file de doc
    ofstream output("number.sorted.txt");       // tao file moi de ghi ket qua sap xep

    if (!input) {                     // neu mo file that bai
        cout << "Failed" << endl;
        return 0;
    }

    vector<int> a;     // vector luu cac so

    int val;
    while (input.good()) {     // doc tung so tu file
        input >> val;
        a.push_back(val);      // them vao vector
    }
    input.close();             // dong file
    sort(a);                   // goi ham sap xep

    for (int i = 0; i < a.size() - 1; i++) {     // ghi ket qua ra file moi
        output << a[i] << " ";
    }
    return 0;
}


//bai tap 2

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void findSubMatrix(vector<vector<int>> v, int rows, int cols) {
    int r1, c1, r2, c2, maxSum = INT_MIN;  // khoi tao bien luu vi tri va tong lon nhat

    for (int top = 0; top < rows; top++) {
        vector<int> tmp(cols, 0);          // vector tam luu tong theo cot

        for (int bottom = top; bottom < rows; bottom++) {
            for (int col = 0; col < cols; col++) {
                tmp[col] += v[bottom][col];  // cong don theo hang
            }

            int sum = 0;
            int c1_start, c2_end;       // vi tri bat dau va ket thuc cua day con co tong lon nhat

            for (int col = 0; col < cols; col++) {
                if (sum < 0) {
                    sum = tmp[col];     // reset neu tong hien tai < 0
                    c1_start = col;
                    c2_end = col;
                }
                else {
                    sum += tmp[col];    // cong tiep vao tong
                    c2_end++;
                }
            }
            if (sum > maxSum) {         // cap nhat neu tim thay tong lon hon
                maxSum = sum;
                r1 = top;
                c1 = c1_start;
                r2 = bottom;
                c2 = c2_end;
            }
        }
    }

    // in ra toa do va tong lon nhat
    cout << r1 + 1 << " " << c1 + 1 << " " << r2 + 1 << " " << c2 + 1 << " " << maxSum;
    return;
}

int main() {
    string s;
    cin >> s;             // nhap ten file
    ifstream input(s);    // mo file

    if (!input) {
        cout << "Khong tim thay file.";  // bao loi neu file khong ton tai
        return 0;
    }
    else {
        int m, n;
        input >> m >> n;      // doc so hang va cot

        vector<vector<int>> matrix(m, vector<int>(n)); // tao ma tran m x n

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                input >> matrix[i][j];   // doc tung gia tri
            }
        }
        findSubMatrix(matrix, m, n);  // goi ham xu ly
    }

    input.close();
    return 0;
}

///bai 3
#include<iostream>
using namespace std;

int GCD(int x, int y) {
    if (y == 0) return x;       // neu y = 0 thi tra ve x
    return GCD(y, x % y);       // goi de quy theo thuat toan Euclid
}

int main() {
    int x;
    int y;
    cin >> x;
    cin >> y;
    cout << GCD(x, y);          // in ra ket qua UCLN
    return 0;
}


//bai 4 
#include<iostream>
#include<vector>
using namespace std;

void print_path(vector<int>path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];         // in ra 1 cau hinh
    }
    cout << endl;
}

void generate_binary(int n, int current, vector<int>path) {
    if (current == n) {
        print_path(path);       // in khi da du do dai
        return;
    }
    else {
        for (int i = 0; i <= 1; i++) {
            path.push_back(i);
            generate_binary(n, current + 1, path); // goi de quy cho vi tri tiep theo
            path.pop_back();    // quay lui
        }
    }
}

int main() {
    int n;
    cin >> n;                     // nhap do dai day
    vector<int>path;
    generate_binary(n, 0, path); // bat dau tu 0
    return 0;
}




//bai 5
#include <iostream>
#include <vector>
using namespace std;


void print_path(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];         // in ra 1 hoan vi
    }
    cout << endl;
}

bool isValid(const vector<int>& path) {
    for (int i = 0; i < path.size() - 1; i++) {
        for (int j = i + 1; j < path.size(); j++) {
            if (path[i] == path[j]) return false; // neu trung lap thi sai
        }
    }
    return true; // khong trung lap
}

void hoanVi(int n, int count, vector<int> path) {
    if (count == n) {
        print_path(path);         // in ra khi du n phan tu
        return;
    }

    for (int i = 1; i <= n; i++) {
        path.push_back(i);

        if (isValid(path)) {       // chi xu ly neu khong bi trung
            hoanVi(n, count + 1, path);
        }

        path.pop_back();          // quay lui
    }
}

int main() {
    int n;
    cin >> n;                     // nhap n
    vector<int> path;
    hoanVi(n, 0, path);           // goi ham bat dau tu 0
    return 0;
}

