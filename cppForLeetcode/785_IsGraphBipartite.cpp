#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> sets(graph.size(), 0);
        for(int i = 0; i < graph.size(); ++i)
        {
            if(sets[i] == 0)
            {
                sets[i] = 1;
                if(dfs(graph, sets, i)) continue;
                else return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, vector<int> &sets, int node)
    {
        int tag = sets[node];
        for(int i : graph[node])
        {
            if(sets[i] == tag)
            {
                return false;
            }
            if(sets[i] == 0)
            {
                sets[i] = -tag;
                if (!dfs(graph, sets, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(void)
{
    //vector<vector<int>> input = {{1,3}, {0,2}, {1,3}, {0,2}};
    //vector<vector<int>> input = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    vector<vector<int>> input = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    //vector<vector<int>> input = {{4},{},{4},{4},{0,2,3}};
    Solution sol;
    cout << sol.isBipartite(input) << endl;
}