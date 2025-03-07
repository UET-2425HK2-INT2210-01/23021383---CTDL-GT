#include <iostream>

using namespace std;

double cal1(int n) {  
    if (n == 0) 
    return 1; 

    double x = 1;  
    if (n < 0) {  
        for (int i = 0; i < -n; i++) {
            x *=  0.5;  
        }
        return x;
    }

    for (int i = 0; i < n; i++) {
        x *= 2;  
    }
    
    return x;
}

/* cal1(n)
    if n == 0
        return 1

    x <- 1
    if  n < 0
     for i <- 1 to n
        x <- x * 0.5

    else for i <- 1 to n
     x <- x * 2

     Do kho : O(n)
*/


int cal2(int n) {
    if (n == 0) return 1;  // Base case: 2^0 = 1

    if (n > 0) return 2 * cal2(n - 1); 
    else return  cal2(n + 1) / 2;       
}


/*
 cal2(n):
    if n == 0 
        RETURN 1  

    if n > 0 
        RETURN 2 * cal2(n - 1)  

    else
        RETURN cal2(n + 1) / 2  
        */
    
int main() {
    int n;
    cin >> n;
    cout << cal2(n);
}
