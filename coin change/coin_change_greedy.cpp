#include <bits/stdc++.h>
using namespace std;

int findMin(int n, vector<int> denomination)
{
    int count = 0;

    for (int i = denomination.size() - 1; i >= 0; i--) {
        while (n >= denomination[i]) {
            n -= denomination[i];
            count++;
        }
    }
    return count;
}

int main()
{
    ifstream fin("input_greedy.txt");
    ofstream fout("output_greedy.txt");

    int n, size;
    fin >> size >> n;

    vector<int> denomination(size);
    for (int i = 0; i < size; ++i) {
        fin >> denomination[i];
    }

    int result = findMin(n, denomination);
    fout << "Minimum coins required: " << result << endl;

    fin.close();
    fout.close();

    return 0;
}
