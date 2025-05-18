#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    const int INF = 1e8;
    int V;
    infile >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int val;
            infile >> val;
            // Assume -1 is used to represent INF in input file
            dist[i][j] = (val == -1) ? INF : val;
        }
    }

    floydWarshall(dist);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF)
                outfile << "INF ";
            else
                outfile << dist[i][j] << " ";
        }
        outfile << "\n";
    }

    infile.close();
    outfile.close();

    return 0;
}
