#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> graph[N];
bool vis[N];

void bfs(int startVertex) {
    queue<int> q;
    q.push(startVertex);
    vis[startVertex] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int edgenumber;
    cout << "Enter the number of edges: ";
    cin >> edgenumber;

    for (int i = 0; i < edgenumber; ++i) {
        cout << "Enter source and destination vertex: ";
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // Undirected graph
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    fill(vis, vis + N, 0); // Reset visited array
    cout << "BFS traversal starting from node " << startVertex << ": ";
    bfs(startVertex);
    cout << endl;

    return 0;
}
