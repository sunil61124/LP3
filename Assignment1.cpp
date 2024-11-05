#include <bits/stdc++.h>
using namespace std;

void fibonacci_non_recursive(int n)
{
    int a = 0;
    int b = 1;
    int i = 2;
    cout << a << ", " << b << ", ";
    int c;
    while (i < n)
    {
        c = a + b;
        cout << c << ", ";
        a = b;
        b = c;
        i++;
    }
}
vector<int> memo(1000, -1);

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    // If value is already computed, return it
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main()
{
    int ch = 0;
    while (ch < 3)
    {
        cout << "\n**************ASSIGNMENT 1*******************";
        cout << "\n1.Non-recursive Fibonacci \n2.Recursive Fibonacci \n3.Exit";
        cout << "\nEnter the choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int a;
            cout << "\nEnter the number : ";
            cin >> a;
            fibonacci_non_recursive(a);
            break;
        case 2:
            cout << "\nRecursive Fibonacci : " << endl;
            int i = 0;
            int n;
            cout << "\nEnter the number : ";
            cin >> n;
            while (i < n)
            {
                cout << fib(i) << ", ";
                i++;
            }
        }
    }
    cout << "\nNon-recursive Fibonacci : " << endl;
    fibonacci_non_recursive(5);
    int n = 10;
    cout << "\nRecursive Fibonacci : " << endl;
    int i = 0;
    while (i < n)
    {
        cout << fib(i) << ", ";
        i++;
    }
}
