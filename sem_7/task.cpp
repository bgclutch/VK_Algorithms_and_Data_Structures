#include <iostream>
#include <vector>
#include <queue>

#if 1
#define VALID_TREE
#endif

#if 0
#define NUMBER_OF_CONNECTED_COMPONENTS
#endif

#ifdef VALID_TREE
bool isValidTree(int n, const std::vector<std::vector<int>>& edges) {
    if (static_cast<int>(edges.size()) != n - 1) {
        return false;
    }

    if (n == 1) return true;

    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited(n, false);
    std::queue<int> q;

    q.push(0);
    visited[0] = true;
    int visitedCount = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visitedCount++;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visitedCount == n;
}

int main() {
    int n1 = 5;
    std::vector<std::vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    std::cout << "Test 1 (Valid Tree): " << (isValidTree(n1, edges1) ? "Yes" : "No") << std::endl;

    int n2 = 4;
    std::vector<std::vector<int>> edges2 = {{0, 1}, {2, 3}};
    std::cout << "Test 2 (Disconnected): " << (isValidTree(n2, edges2) ? "Yes" : "No") << std::endl;

    return 0;
}

#endif

#ifdef NUMBER_OF_CONNECTED_COMPONENTS
void dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int countComponents(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    int n = 5;
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int result = countComponents(n, edges);
    std::cout << "Number of connected components: " << result << std::endl;
    return 0;
}
#endif