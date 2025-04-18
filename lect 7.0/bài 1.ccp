
#include <iostream>
#include <vector>
using namespace std;
int sum = 0;//khai báo tổng ở cục bộ(không bị ảnh hưởng bởi đệ quy)
int recursion(int n) {
    if (n == 0) return sum;//Điều kiện dừng đệ quy
    sum += n;//Tổng cộng với n
    n--;//n trừ dần
    recursion(n);//Đệ quy
}

int main() {
    int n;
    cin >> n;//Input
    cout << recursion(n);//Output
    return 0;
}
