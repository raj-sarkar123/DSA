class Solution {
public:
    void dfs(vector<vector<int>>& edges, int node, vector<bool>& visited,
             vector<vector<int>>& adj) {
        visited[node] = true;
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(edges, neighbour, visited,adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        dfs(edges, source, visited, adj);
        return visited[destination];
    }
};