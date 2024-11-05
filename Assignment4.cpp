
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Knapsack {
    int n;
    int w;
    vector<pair<int, int>> input; // (profit, weight)
    vector<vector<int>> ans;

public:
    void accept();
    void display();
    void zero_one_knapsack();
};

void Knapsack::accept() {
    cout << "\nEnter the number of items: ";
    cin >> n;
    cout << "\nEnter the capacity of bag ";
    cin >> w;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the profit and weight: ";
        cin >> input[i].first >> input[i].second;
    }
    ans.resize(n + 1, vector<int>(w + 1, 0));
}

void Knapsack::zero_one_knapsack() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                ans[i][j] = 0;
            } else if (input[i - 1].second <= j) {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - input[i - 1].second] + input[i - 1].first);
            } else {
                ans[i][j] = ans[i - 1][j];
            } 
        }
    }
}


void Knapsack::display() {
    cout << "\nProfit\t\tWeight" << endl;
    for (const auto& item : input) {
        cout << item.first << "\t\t" << item.second << endl;
    }
    cout << "\nMaximum profit: " << ans[n][w] << endl;
}

int main() {
    Knapsack obj;

    obj.accept();
    obj.zero_one_knapsack();
    obj.display();

    return 0;
}
