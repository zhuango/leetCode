#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mapping;
        for (auto a: tasks)
        {
            mapping[a] += 1;
        }
        priority_queue<pair<int, char>> pq;
        for (auto p : mapping)
        {
            pq.push(make_pair(p.second, p.first));
        }
        int alltime = 0;
        int cycle = n + 1;
        int executedTaskCount = 0;
        vector<pair<int, char>> executedTasks;
        while(!pq.empty())
        {
            executedTasks.clear();
            executedTaskCount = 0;
            for (int i = 0; i < cycle; ++i)
            {
                if (!pq.empty())
                {
                    executedTasks.push_back(pq.top());
                    pq.pop();
                    executedTaskCount ++;
                }
            }
            for (auto &pair : executedTasks)
            {
                if (--pair.first)
                {
                    pq.push(pair);
                }
            }
            alltime += pq.empty() ? executedTaskCount : cycle;
        }
        return alltime;
    }
};