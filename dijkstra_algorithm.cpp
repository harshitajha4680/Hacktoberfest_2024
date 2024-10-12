#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int source, const vector<vector<pair<int, int>>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_vertex = pq.top().second;
        pq.pop();

        if (curr_dist > distances[curr_vertex]) {
            continue;
        }

        for (const auto& neighbor : graph[curr_vertex]) {
            int next_vertex = neighbor.first;
            int weight = neighbor.second;

            if (distances[curr_vertex] + weight < distances[next_vertex]) {
                distances[next_vertex] = distances[curr_vertex] + weight;
                pq.push({distances[next_vertex], next_vertex});
            }
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<pair<int, int>>> graph(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> distances(vertices, INF);
    dijkstra(source, graph, distances);

    for (int i = 0; i < vertices; i++) {
        if (distances[i] == INF) {
            cout << "Vertex " << i << ": INF\n";
        } else {
            cout << "Vertex " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}
