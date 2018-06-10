#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        K -= 1;
        vector<bool> visited(N, false);
        int mm = 0x7fffffff;
        vector<int> distance(N, mm);
        distance[K] = 0;
        vector<vector<int>> m(N, vector<int>(N, mm));
        vector<vector<int>> mapping(N);
        for(auto &edge : times)
        {
            m[edge[0]-1][edge[1]-1] = edge[2];
            mapping[edge[0]-1].push_back(edge[1]-1);
        }
        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push({K, 0});
        while(!pq.empty())
        {
            pair<int, int> node = pq.top();
            pq.pop();
            visited[node.first] = true;
            for(int i : mapping[node.first])
            {
                int old = distance[i];
                distance[i] = min(distance[i], node.second + m[node.first][i]);
                if (distance[i] < old)
                {
                    pq.push({i, distance[i]});
                }
            }
        }
        int result = 0;
        for(int i : distance)
        {
            if(i > result) result = i;
        }
        if(result != mm) return result;
        return -1;
    }
};

int main(void)
{
    vector<vector<int>> input = {{1, 2, 1},{2,3,2},{1,3,4}};
    Solution sol;
    cout << sol.networkDelayTime(input, 3, 1) << endl;
}