#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Recursive function to find number of operations 
int editDistRec(string& s1, string& s2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;

    if (s1[m - 1] == s2[n - 1])
        return editDistRec(s1, s2, m - 1, n - 1);

    return 1 + min({editDistRec(s1, s2, m, n - 1),  
                    editDistRec(s1, s2, m - 1, n),   
                    editDistRec(s1, s2, m - 1, n - 1)}); 
}

// Wrapper function
int editDistance(string& s1, string& s2) {
    return editDistRec(s1, s2, s1.length(), s2.length());
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string s1, s2;
    fin >> s1 >> s2;

    int result = editDistance(s1, s2);

    fout << "Minimum Edit Distance = " << result << endl;

    fin.close();
    fout.close();

    return 0;
}
