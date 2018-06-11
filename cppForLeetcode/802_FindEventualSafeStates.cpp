#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> tag(graph.size(), 0);
        for(int i = 0; i < graph.size(); ++i)
        {
            hasLoop(graph, visited, tag, i);
        }
        vector<int> resutls;
        for(int i = 0; i < tag.size(); ++i)
        {
            if(tag[i] == -1)
            {
                resutls.push_back(i);
            }
        }
        return resutls;
    }
    bool hasLoop(vector<vector<int>>& graph, vector<bool> &visited, vector<int> &tag, int node)
    {
        if(visited[node]) return true;
        visited[node] = true;
        for(int i : graph[node])
        {
            if(tag[i] == 1)
            {
                tag[node] = 1;
            }
            else if(tag[i] == 0)
            {
                if(hasLoop(graph, visited, tag, i))
                {
                    tag[node] = 1;
                }
            }
        }
        visited[node] = false;
        if (tag[node] != 1) tag[node]=-1;
        return tag[node] == 1;
    }
};