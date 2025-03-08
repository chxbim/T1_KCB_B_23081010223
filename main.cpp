#include <bits/stdc++.h>
using namespace std;

class Graf {
public:
    unordered_map<string, vector<string>> adj;

    void addEdge(string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(string start, string finish) {
        if (adj.find(start) == adj.end() || adj.find(finish) == adj.end()) {
            cout << "Masukkan nama salah satu/kedua kota dengan benar!" << endl;
            return;
        }

        queue<vector<string>> q;
        unordered_set<string> done;

        q.push({start});
        done.insert(start);

        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();
            string lastNode = path.back();

            if (lastNode == finish) {
                cout << "Jalan tercepat dari " << start << " ke " << finish << ":" << endl;
                for (string kota : path) cout << kota << endl;
                return;
            }

            for (string neighbor : adj[lastNode]) {
                if (done.find(neighbor) == done.end()) {
                    vector<string> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(newPath);
                    done.insert(neighbor);
                }
            }
        }

        cout << "Tidak ada jalan dari " << start << " ke " << finish << endl;
    }
};

int main() {
    Graf g;

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
    cout << "Masukkan kota asal: ";
    cin >> startCity;
    cout << "Masukkan kota tujuan: ";
    cin >> goalCity;

    cout << "\nHasil BFS dari " << startCity << " ke " << goalCity << "..." << endl;
    g.BFS(startCity, goalCity);

    return 0;
}
