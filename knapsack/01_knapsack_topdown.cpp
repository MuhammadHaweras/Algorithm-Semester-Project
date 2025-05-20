#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, 
                vector<vector<int>> &memo) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);

    int notPick = knapsackRec(W, val, wt, n - 1, memo);

    return memo[n][W] = max(pick, notPick);
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    return knapsackRec(W, val, wt, n, memo);
}

int main() {
    ifstream infile("01_knapsack_topdown_input.txt");
    ofstream outfile("01_knapsack_topdown_output.txt");

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
