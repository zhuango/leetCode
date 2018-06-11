#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for(bool b : visited)
        {
            if(!b) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int node)
    {
        if(visited[node]) return ;
        visited[node] = true;
        for(int i : rooms[node])
        {
            dfs(rooms, visited, i);
        }
    }
};