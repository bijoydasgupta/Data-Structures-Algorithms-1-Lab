#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);

    cout << "DFS Traversal: ";
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
        }

        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) st.push(neighbor);
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);
    dfs(start, adj, visited);

    return 0;
}
