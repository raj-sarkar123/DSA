class Solution {
public:
    void helper(vector<vector<int>>& rooms, vector<bool>& visited,int room) {
        visited[room] = true;
        for(int key:rooms[room]){
            if(!visited[key]){
                helper(rooms,visited,key);
            }
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        helper(rooms, visited,0);
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == false) {
                return false;
            }
        }

        return true;
    }
};