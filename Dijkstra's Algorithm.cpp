#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <unordered_map>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void dijkstra(const vector<vector<int>> &graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INF);        
    vector<int> parent(n, -1);       
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int node = pq.top().first;
        int nodeDist = pq.top().second;
        pq.pop();

        if (nodeDist > dist[node]) continue;

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[node][neighbor] != 0) { // Check for an edge
                int newDist = dist[node] + graph[node][neighbor];

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    parent[neighbor] = node;
                    pq.push({neighbor, newDist});
                }
            }
        }
    }

    if (dist[end] == INF) {
        cout << "No path exists between " << start << " and " << end << ".\n";
        return;
    }

    cout << "Shortest path cost: " << dist[end] << "\nPath: ";
    
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i == path.size() - 1 ? "\n" : " -> ");
    }
}

int main() {
    int n, start, end, choice;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Choose graph input method:\n1. Manual input\n2. Use hardcoded example\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter adjacency matrix (0 for no edge, positive weight for edge):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
    } else {
        // Hardcoded example graph
        graph = {
            {0, 10, 3, 0, 0},
            {10, 0, 1, 2, 0},
            {3, 1, 0, 8, 2},
            {0, 2, 8, 0, 4},
            {0, 0, 2, 4, 0}
        };
        n = graph.size();
    }

    cout << "Enter start node (0 to " << n-1 << "): ";
    cin >> start;
    cout << "Enter end node (0 to " << n-1 << "): ";
    cin >> end;

    dijkstra(graph, start, end);

    return 0;
}
