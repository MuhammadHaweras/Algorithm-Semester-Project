#include <bits/stdc++.h>
using namespace std;

// Comparison function to sort items based on value/weight ratio
bool compare(vector<int>& a, vector<int>& b) {
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    
    // Create 2D vector to store value and weight
    vector<vector<int>> items(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }
    
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);
    
    double res = 0.0;
    int currentCapacity = capacity;

    // Process items in sorted order
    for (int i = 0; i < n; i++) {
        if (items[i][1] <= currentCapacity) {
            res += items[i][0];
            currentCapacity -= items[i][1];
        } else {
            res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;
            break;
        }
    }
    
    return res;
}

int main() {
    ifstream fin("input_fractional.txt");
    ofstream fout("output_fractional.txt");

    int n, capacity;
    fin >> n >> capacity;

    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++)
        fin >> val[i];
    for (int i = 0; i < n; i++)
        fin >> wt[i];

    double result = fractionalKnapsack(val, wt, capacity);

    fout << fixed << setprecision(2);
    fout << "Maximum value in Knapsack = " << result << endl;

    fin.close();
    fout.close();

    return 0;
}
