#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<string>> adj;

    void addEdge(string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Karena graf tidak berarah
    }

    void BFS(string start, string goal) {
        if (adj.find(start) == adj.end() || adj.find(goal) == adj.end()) {
            cout << "Error: One or both cities do not exist in the graph.\n";
            return;
        }

        queue<vector<string>> q;
        unordered_set<string> visited;

        q.push({start});
        visited.insert(start);

        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();
            string lastNode = path.back();

            // Jika mencapai tujuan, cetak jalurnya
            if (lastNode == goal) {
                cout << "Jalan tercepat dari " << start << " ke " << goal << ":" << endl;
                for (string city : path) cout << city << endl;
                return;
            }

            // Eksplorasi semua tetangga yang belum dikunjungi
            for (string neighbor : adj[lastNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    vector<string> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(newPath);
                    visited.insert(neighbor);
                }
            }
        }

        cout << "No path found from " << start << " to " << goal << endl;
    }
};

int main() {
    Graph g;

    // Menambahkan edge berdasarkan peta Romania
    g.addEdge("Arad", "Zerind");
    g.addEdge("Arad", "Sibiu");
    g.addEdge("Arad", "Timisoara");
    g.addEdge("Zerind", "Oradea");
    g.addEdge("Oradea", "Sibiu");
    g.addEdge("Timisoara", "Lugoj");
    g.addEdge("Lugoj", "Mehadia");
    g.addEdge("Mehadia", "Dobreta");
    g.addEdge("Dobreta", "Craiova");
    g.addEdge("Craiova", "Rimnicu Vilcea");
    g.addEdge("Craiova", "Pitesti");
    g.addEdge("Rimnicu Vilcea", "Sibiu");
    g.addEdge("Rimnicu Vilcea", "Pitesti");
    g.addEdge("Pitesti", "Bucharest");
    g.addEdge("Fagaras", "Sibiu");
    g.addEdge("Fagaras", "Bucharest");
    g.addEdge("Bucharest", "Giurgiu");
    g.addEdge("Bucharest", "Urziceni");
    g.addEdge("Urziceni", "Vaslui");
    g.addEdge("Urziceni", "Hirsova");
    g.addEdge("Hirsova", "Eforie");
    g.addEdge("Vaslui", "Iasi");
    g.addEdge("Iasi", "Neamt");

    string startCity, goalCity;
    cout << "Enter start city: ";
    cin >> startCity;
    cout << "Enter goal city: ";
    cin >> goalCity;

    cout << "\nHasil BFS dari " << startCity << " ke " << goalCity << "..." << endl;
    g.BFS(startCity, goalCity);

    return 0;
}
