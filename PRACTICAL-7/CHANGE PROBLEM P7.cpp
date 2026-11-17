#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class CoinChange {
private:
    vector<int> coins;
    int n, amount;
    vector<int> dp;

public:
    void getInput() {
        cout << "Enter number of coin denominations: ";
        cin >> n;

        cout << "Enter coin denominations: ";
        coins.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }

        cout << "Enter the amount: ";
        cin >> amount;
    }

    void solve() {
        dp.resize(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        if (dp[amount] == INT_MAX) {
            cout << "\nAmount cannot be formed using the given coins.";
        } else {
            cout << "\nMinimum number of coins required: "
                 << dp[amount] << endl;
        }
    }
};

int main() {
    CoinChange obj;

    obj.getInput();
    obj.solve();

    return 0;
}