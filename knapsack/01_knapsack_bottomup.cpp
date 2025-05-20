#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                int pick = 0;
                if (wt[i - 1] <= j)
                    pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                int notPick = dp[i - 1][j];
                dp[i][j] = max(pick, notPick);
            }
        }
    }

    return dp[n][W];
}

int main() {
    ifstream infile("01_knapsack_bottomup_input.txt");
    ofstream outfile("01_knapsack_bottomup_output.txt");

    int n, W;
    infile >> n >> W;

    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++) infile >> val[i];
    for (int i = 0; i < n; i++) infile >> wt[i];

    int result = knapsack(W, val, wt);

    outfile << "Maximum value in knapsack: " << result << endl;

    infile.close();
    outfile.close();

    return 0;
}
