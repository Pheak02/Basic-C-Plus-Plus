#include <iostream>
#include <vector>
#include <utility> // For pair

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

// Depth First Search (DFS) function to find the highest cost path
void DFS(vector<pair<int, int>> adj[], int v, int visited[], vector<int>& path, int cost, int &maxCost, vector<int>& maxCostPath) {
    visited[v] = 1; // Mark current vertex as visited
    path.push_back(v); // Add current vertex to the path

    // Base case: if current cost is greater than previous max cost, update max cost and max cost path
    if (cost > maxCost) {
        maxCost = cost;
        maxCostPath = path;
    }

    // Recursive call for all adjacent vertices of current vertex
    for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
        int u = it->first;
        int weight = it->second;
        if (visited[u] == 0) {
            DFS(adj, u, visited, path, cost + weight, maxCost, maxCostPath);
        }
    }

    // Backtrack: remove current vertex from path and mark it as unvisited
    path.pop_back();
    visited[v] = 0;
}

// Function to find the path with the highest cost
vector<int> findHighestCostPath(vector<pair<int, int>> adj[], int V) {
    // Initialize visited array and path array
    int visited[V] = {0};
    vector<int> path;
    
    // Initialize max cost and max cost path
    int maxCost = 0;
    vector<int> maxCostPath;

    // DFS from each vertex to find the highest cost path
    for (int i = 0; i < V; i++) {
        DFS(adj, i, visited, path, 0, maxCost, maxCostPath);
    }

    return maxCostPath;
}

int main() {
    int V = 9; // Number of vertices

    // Array of vectors to represent the graph
    vector<pair<int, int>> adj[V];

    // Adding edges to the graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);

    addEdge(adj, 2, 1, 8);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 2, 3, 7);

    addEdge(adj, 3, 5, 14);
    addEdge(adj, 3, 4, 9);

    addEdge(adj, 4, 5, 10);

    addEdge(adj, 5, 6, 2);

    addEdge(adj, 6, 8, 6);
    addEdge(adj, 6, 7, 1);

    addEdge(adj, 7, 8, 7);

    // Find the path with the highest cost
    vector<int> maxCostPath = findHighestCostPath(adj, V);

    // Print the path with the highest cost
    cout << "Path with highest cost: ";
    for (int i = 0; i < maxCostPath.size(); i++) {
        cout << maxCostPath[i] << " ";
    }
    cout << endl;

    return 0;
}

