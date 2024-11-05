#include <iostream>
using namespace std;

void fibonacciRecursiveHelper(int prev1, int prev2, int n){
    if(n == 0) return;
    int current = prev1+prev2;
    cout<< current<<" ";
    fibonacciRecursiveHelper(prev2, current, n-1);
}
 
 void fibonacciRecursive(int n){
    if (n < 1){
        cout<< "Series: " << 0 << endl;
        return;
    }
    if (n == 1){
        cout<< "Series: " << 0 << " " << 1 << endl;
        return;
    }
    cout<<"Series"<< 0 <<" "<< 1<< " ";
    fibonacciRecursiveHelper(0, 1 , n-1);
    cout<< endl;
 }
  int main()
  {
    int n;
    cout<<" Enter the number of series u wnt: ";
    cin>> n;
    fibonacciRecursive(n);
    return 0;
  }