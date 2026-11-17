#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Knapsack {

private:
    vector<int> w;              // weights
    vector<int> v;              // values
    int n, W;                   // number of items and capacity
    vector<vector<int>> dp;     // DP table

public:

    // Get Input
    void getInput() {

        cout << "Enter number of items : ";
        cin >> n;

        cout << "Enter knapsack capacity : ";
        cin >> W;

        w.resize(n + 1);
        v.resize(n + 1);

        // Creating DP table
        // Time Complexity = O(nW)
        dp.assign(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            cout << "Item " << i
                 << " weight and value : ";
            cin >> w[i] >> v[i];
        }
    }

    // Solve Knapsack using Dynamic Programming
    void solve() {

        // Time Complexity = O(nW)
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= W; j++) {

                if (w[i] <= j) {

                    dp[i][j] = max(
                        v[i] + dp[i - 1][j - w[i]],
                        dp[i - 1][j]
                    );

                } else {

                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    // Print DP Table
    void printTable() {

        cout << "\nDP Table:\n ";

        for (int j = 0; j <= W; j++) {
            cout << j << " ";
        }

        cout << endl;

        // Time Complexity = O(nW)
        for (int i = 0; i <= n; i++) {

            cout << "i=" << i << " ";

            for (int j = 0; j <= W; j++) {
                cout << dp[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Find Selected Items
    void findItems() {

        cout << "\nSelected Items:\n";

        int j = W;

        // Time Complexity = O(n)
        for (int i = n; i >= 1; i--) {

            if (dp[i][j] != dp[i - 1][j]) {

                cout << "Item " << i
                     << " (w=" << w[i]
                     << ", v=" << v[i]
                     << ") TAKEN\n";

                j -= w[i];

            } else {

                cout << "Item " << i
                     << " (w=" << w[i]
                     << ", v=" << v[i]
                     << ") NOT taken\n";
            }
        }
    }

    // Show Result
    void showResult() {

        cout << "\nMaximum Value = "
             << dp[n][W] << endl;
    }
};

int main() {

    Knapsack k;

    k.getInput();
    k.solve();
    k.printTable();
    k.showResult();
    k.findItems();

    return 0;
}