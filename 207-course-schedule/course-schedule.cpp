class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Build adjacency list
        vector<vector<int>> a(numCourses);
        vector<int> degree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++) {

            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];

            a[prerequisite].push_back(course);
            degree[course]++;
        }

        queue<int> q;

        // Add courses with 0 prerequisites
        for(int i = 0; i < numCourses; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for(int i = 0; i < a[node].size(); i++) {

                int neighbour = a[node][i];

                degree[neighbour]--;

                if(degree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // If all courses were processed → no cycle
        return count == numCourses;
    }
};