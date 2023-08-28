#include<bits/stdc++.h>
using namespace std;

class Graph {
    int numVertices; // Number of vertices
    list<int> *adjLists; // Array of linked lists to store adjacent vertices
    
public:
    Graph(int V) {
        numVertices = V;
        adjLists = new list<int>[V];
    }
    
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }
    
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto v : adjLists[i])
                cout << v << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    g.printGraph();
    
    return 0;
}