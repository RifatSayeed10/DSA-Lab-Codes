#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex) {
    vis[vertex] = true;
    cout << vertex << " ";

    for (int child : graph[vertex]) {
        if (!vis[child]) {
            dfs(child);
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
        graph[v2].push_back(v1); // undirected
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    fill(vis, vis + N, false); // reset visited
    cout << "DFS traversal starting from node " << startVertex << ": ";
    dfs(startVertex);
    cout << endl;

    return 0;
}
