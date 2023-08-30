#include <iostream>
#include <vector>
#include <utility> // For pair

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

// Function to print the graph
void printGraph(vector<pair<int, int>> adj[], int V) {
    for(int i = 0; i < V; i++) {
        cout << "Adjacency list of vertex " << i << endl;
        for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << "-> " << it->first << " (weight: " << it->second << ")";
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Number of vertices

    // Array of vectors to represent the graph
    vector<pair<int, int>> adj[V];

    // Adding edges to the graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);

    addEdge(adj, 2, 1, 8);
    addEdge(adj, 2,8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 2, 3, 7);

    addEdge(adj, 3, 5, 14);
    addEdge(adj, 3, 4, 9);

    addEdge(adj, 4, 5, 10);

    addEdge(adj, 5, 6, 2);

    addEdge(adj, 6, 8, 6);
    addEdge(adj, 6, 7,1);

    addEdge(adj, 7, 8, 7);









    // Printing the graph
    printGraph(adj, V);

    return 0;
}