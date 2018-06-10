#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> mapping;
        unordered_map<int, int> q2u;
        vector<int> answer(quiet.size(), 0x7fffffff);
        vector<int> rich(quiet.size(), 0x7fffffff);
        for(auto &edge : richer)
        {
            mapping[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < quiet.size(); ++i)
        {
            q2u[quiet[i]] = i;
        }
        vector<bool> visited(quiet.size(), false);
        for(int i = 0; i < quiet.size(); ++i)
        {
            if(visited[i]) continue;
            dfs(mapping, visited, i, rich, quiet);
        }

        for(int i = 0; i < rich.size(); ++i)
        {
            answer[i] = q2u[rich[i]];
        }
        return answer;
    }
    void dfs(unordered_map<int, vector<int>> &mapping, vector<bool> &visited, int node, vector<int> &rich, vector<int>& quiet)
    {
        rich[node] = min(rich[node], quiet[node]);
        visited[node] = true;
        for(int i : mapping[node])
        {
            rich[node] = min(rich[node], quiet[i]);
            if(!visited[i])
            {
                dfs(mapping, visited, i, rich, quiet);
            }
            rich[node] = min(rich[node], rich[i]);
        }
    }
};


int main(void)
{
    vector<vector<int>> input0 = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> input1 = {3,2,5,4,6,1,7,0};
    Solution sol;
    for(int a : sol.loudAndRich(input0, input1))
    {
        cout << a << " ";
    }
    cout << endl;
}