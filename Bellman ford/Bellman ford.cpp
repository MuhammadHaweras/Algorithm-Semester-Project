#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        bool updated = false;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            return {};
        }
    }

    return dist;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input.txt." << endl;
        return 1;
    }

    int V, E, src;
    inputFile >> V >> E >> src;
    if (inputFile.fail()) {
        cerr << "Error: Invalid format in input.txt" << endl;
        return 1;
    }

    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        inputFile >> u >> v >> wt;
        if (inputFile.fail()) {
            cerr << "Error: Invalid edge data in input.txt" << endl;
            return 1;
        }
        edges.push_back({u, v, wt});
    }
    inputFile.close();

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create output.txt" << endl;
        return 1;
    }

    vector<int> result = bellmanFord(V, edges, src);

    if (result.empty()) {
        outputFile << "Graph contains a negative-weight cycle!" << endl;
    } else {
        outputFile << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            outputFile << "Node " << i << ": ";
            if (result[i] == INT_MAX) outputFile << "INF";
            else outputFile << result[i];
            outputFile << endl;
        }
    }
    outputFile.close();

    return 0;
}
