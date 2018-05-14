#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> distance(N, 0);
        map<int, int> tofather;
        map<int, vector<int>> tochildren;
        for(auto &edge : edges)
        {
            tofather[edge[1]] = edge[0];
            tochildren[edge[0]].push_back(edge[1]);
            tochildren[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < N; ++i)
        {
            queue<pair<int, int>> q;
            vector<bool> visited(N, false);
            q.push({i, 0});
            while(!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                int curNode = cur.first;
                int length = cur.second;

                visited[curNode] = true;
                for(int c : tochildren[curNode])
                {
                    if(visited[c]) continue;
                    distance[i] += length + 1;
                    q.push({c, length + 1});
                }
            }
        }
        return distance;

    }
};
