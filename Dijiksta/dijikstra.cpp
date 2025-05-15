#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
using namespace std;

// Build adjacency list
vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V) {
    vector<vector<vector<int>>> adj(V);
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return adj;
}

// Dijkstra's algorithm
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<vector<int>>> adj = constructAdj(edges, V);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();

        for (auto x : adj[u]) {
            int v = x[0];
            int weight = x[1];

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int V, E;
    infile >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; ++i) {
        infile >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    infile >> src;

    vector<int> dist = dijkstra(V, edges, src);

    outfile << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < dist.size(); ++i) {
        outfile << "To " << i << ": " << dist[i] << "\n";
    }

    infile.close();
    outfile.close();

    return 0;
}
