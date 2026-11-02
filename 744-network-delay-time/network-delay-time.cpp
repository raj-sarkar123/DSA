class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int src) {
        n++;
		vector<vector<vector<int>>> a(n);
		for (int i = 0; i<edges.size(); i++) {
			
				int s = edges[i][0];
				int d = edges[i][1];
				int w = edges[i][2];
				
				
				a[s].push_back({d, w});
				
			
			
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		vector<int>dist(n, INT_MAX);
		dist[src] = 0;
		pq.push({0, src});
		while (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			int d = p.first;
			int node = p.second;
			if (d>dist[node]) {
				continue;
			}
			for (int j = 0; j<a[node].size(); j++) {
				int neigh = a[node][j][0];
				int wt = a[node][j][1];
				
				if ((d + wt) < dist[neigh]) {
					dist[neigh] = wt + d;
					pq.push({d + wt, neigh});
				}
			}
		}
        int ans = 0;
		for (int i = 1; i <n; i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};