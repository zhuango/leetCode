#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> count(N, 0);
        vector<int> result(N, 0);
        map<int, int> tofather;
        map<int, vector<int>> tochildren;
        for(auto &edge : edges)
        {
            if(edge[1] < edge[0])
            {
                tofather[edge[0]] = edge[1];
                tochildren[edge[1]].push_back(edge[0]);
            }
            else
            {
                tofather[edge[1]] = edge[0];
                tochildren[edge[0]].push_back(edge[1]);
            }
        }
        for(int i = 0; i < N; ++i)
        {
            queue<pair<int, int>> q;
            q.push({i, 0});
            count[i] = 1;
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                int curNode = cur.first;
                int length = cur.second;

                for(int c : tochildren[curNode])
                {
                    count[i] += 1;
                    result[i] += length + 1;
                    q.push({c, length + 1});
                }
            }
            if(i!=0)
            {
                int father = tofather[i];
                result[i] = result[father] - count[i] * 2 + N;
            }
        }
        return result;
    }
};
