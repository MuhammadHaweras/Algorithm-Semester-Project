#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                if(i == V - 1)
                    return {-1}; // Negative weight cycle
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int V, E, src;
    infile >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        infile >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    infile >> src;

    vector<int> ans = bellmanFord(V, edges, src);

    if (ans.size() == 1 && ans[0] == -1) {
        outfile << "Negative weight cycle detected";
    } else {
        for (int dist : ans)
            outfile << dist << " ";
    }

    infile.close();
    outfile.close();

    return 0;
}
