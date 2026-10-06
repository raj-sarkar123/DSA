class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> a(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            a[src].push_back(dest);

            degree[dest]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            count++;

            for (int i = 0; i < a[node].size(); i++) {
                int neighbour = a[node][i];
                degree[neighbour]--;

                if (degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        reverse(res.begin(), res.end());
      return (count == n) ? res : vector<int>{};
    }
};