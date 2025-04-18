#include <iostream>
using namespace std;
int ans = 1;
int recursion(int x,int n) {
    if (n == 0) return ans;
    ans *= x;
    n--;
     recursion(x,n);
}

int main() {
    int x,n;
    cin >> x>>n;
    cout << recursion(x,n);
    return 0;
}
