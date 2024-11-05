#include <iostream>
using namespace std;

void fibonacciIterative(int n) {
    if (n < 1) {
        cout << "Series: " << 0 << endl;
        return;
    }
    if (n == 1) {
        cout << "Series: " << 0 << " " << 1 << endl;
        return;
    }
        int prev1 = 0, prev2 = 1;
    cout << "Series: " << prev1 << " " << prev2 << " "; 
    
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2; 
        cout << current << " ";      
        prev1 = prev2;               
        prev2 = current;             
    }
    cout << endl;                    
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;
    fibonacciIterative(n);
    return 0;
}
