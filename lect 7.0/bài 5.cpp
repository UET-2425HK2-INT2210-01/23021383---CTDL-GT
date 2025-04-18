#include <iostream>
using namespace std;
int ans = 0;
int recursion(int n) {
    if (n == 0) return ans;
    n /= 10;
    ans++;
     recursion(n);
}

int main() {
    int n;
    cin>>n;
    cout << recursion(n);
    return 0;
}
