
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class N_queen
{
    vector<vector<string>> board;
    vector<vector<vector<string>>> solutions;
    int n;

public:
    N_queen(int size)
    {
        n = size;
        board.resize(n, vector<string>(n, ". "));
    }

    bool isvalid(int row, int col)
    {
        // Check if no queens are in the same column
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == "Q ")
                return false;
        }

        // Check left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "Q ")
                return false;
        }

        // Check right diagonal
        for (int i = row, k = col; i >= 0 && k < n; i--, k++)
        {
            if (board[i][k] == "Q ")
                return false;
        }

        return true;
    }

    void solve(int row)
    {
        if (row == n)
        {
            // Store the current board configuration as a valid solution
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isvalid(row, col))
            {
                board[row][col] = "Q ";
                solve(row + 1);
                board[row][col] = ". "; // Backtrack
            }
        }
    }

    void display()
    {
        // Place the first queen at (0, 0)
        board[0][0] = "Q ";
        solve(1);  // Start solving from the next row

        int cnt = 0;
        if (solutions.empty())
        {
            cout << "No solution exists for N = " << n << endl;
            return;
        }

        for (const auto &solution : solutions)
        {
            cout << "-------------------------\n";
            cout << "Solution " << cnt + 1 << ":\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << solution[i][j] << " ";
                }
                cout << endl;
            }
            cnt++;
            cout << endl;
        }

        cout << "Total solutions: " << solutions.size() << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the board (N): ";
    cin >> size;

    N_queen obj(size);

    obj.display();

    return 0;
}
