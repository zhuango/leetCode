#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        visited.resize(numCourses, false);
        tag.resize(numCourses, false);
        vector<vector<int>> graph(numCourses);
        vector<int> rudu(numCourses, 0);
        for(auto & pair : prerequisites)
        {
            graph[pair.first].push_back(pair.second);
            rudu[pair.second] += 1;
        }
        vector<int> results;
        for(int i = 0; i < numCourses; ++i)
        {
            if(hasLoop(graph, i))
            {
                return results;
            }
        }
        
        queue<int> zeroRudu;
        for(int i = 0; i < numCourses; ++i) if(rudu[i] == 0) zeroRudu.push(i);
        while(!zeroRudu.empty())
        {
            int node = zeroRudu.front();
            zeroRudu.pop();
            results.push_back(node);
            for(int i : graph[node])
            {
                rudu[i] -= 1;
                if(rudu[i] == 0) zeroRudu.push(i);
            }
        }
        return vector<int>(results.rbegin(), results.rend());
    }
    bool hasLoop(vector<vector<int>> &graph, int node)
    {
        if(visited[node]) return false;
        if(tag[node]) return true;
        tag[node] = true;
        for(int i : graph[node])
        {
            if(hasLoop(graph, i))
            {
                return true;
            }
        }
        tag[node] = false;
        visited[node] = true;
        return false;
    }
private:
    vector<bool> visited;
    vector<bool> tag;
};