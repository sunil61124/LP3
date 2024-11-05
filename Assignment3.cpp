
#include<bits/stdc++.h>
using namespace std;

class fract_knapsack {
    int n;
    int w;

    vector<pair<double, double>> input;

public:
    void accept();
    void display();
    void fract_oper();
};

void fract_knapsack::accept() {
    cout << "\nEnter the size of array : ";
    cin >> n;

    cout << "\nEnter the capacity of knapsack bag : ";
    cin >> w;
    input.resize(n);

    for (int i = 0; i < n; i++) {
        double profit, weight;
        cout << "\nEnter the profit and weight (For eg: 10 2) : ";
        cin >> profit >> weight;

        input[i] = {profit, weight};
    }

    sort(input.begin(), input.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
        return (a.first / a.second) > (b.first / b.second);
    });

    display();
    fract_oper();
}

void fract_knapsack::fract_oper() {
    int total_wt = w;
    double ans = 0;

    for (const auto& item : input) {
        double item_profit = item.first;
        double item_weight = item.second;

        if (item_weight <= total_wt) {
            total_wt -= item_weight;
            ans += item_profit;
        } else {
            ans += item_profit * (static_cast<double>(total_wt) / item_weight);
            break;
        }
    }

    cout << "\nMaximum Profit : " << ans;
}

void fract_knapsack::display() {
    cout << "\nProfit\t\tWeight\t\tProfit/Weight" << endl;
    for (const auto& item : input) {
        double profit = item.first;
        double weight = item.second;
        double ratio = profit / weight;
        cout << profit << "\t\t" << weight << "\t\t" << ratio << endl;
    }
}

int main() {
    fract_knapsack obj;
    obj.accept();
}
