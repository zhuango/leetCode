#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    tuple<int, int, int, int> argmin(vector<int> &cost)
    {
        int m1pos = -1;
        int m1 = 0x7fffffff;
        int m2pos = -1;
        int m2 = 0x7fffffff;
        for(int i = 0; i < cost.size(); ++i)
        {
            if(cost[i] < m1)
            {
                m2 = m1;
                m2pos = m1pos;
                m1 = cost[i];
                m1pos = i;
            }
            else if(cost[i] < m2)
            {
                m2 = cost[i];
                m2pos = i;
            }
        }
        return make_tuple(m1, m1pos, m2, m2pos);
    }
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0) return 0;
        vector<vector<int>> maxp(costs.size(), vector<int> (costs[0].size(), 0x7fffffff));
        for(int i = 0; i < costs[0].size(); ++i)
        {
            maxp[0][i] = costs[0][i];
        }
        for(int i = 1; i < costs.size(); ++i)
        {
            tuple<int, int, int, int> mmtuple = argmin(maxp[i-1]);
            int m1 = get<0>(mmtuple);
            int m1pos = get<1>(mmtuple);
            int m2 = get<2>(mmtuple);
            int m2pos = get<3>(mmtuple);
            for(int j = 0; j < costs[i].size(); ++j)
            {
                if(j == m1pos) maxp[i][j] = m2 + costs[i][j];
                else maxp[i][j] = m1 + costs[i][j];
            }
        }
        return *min_element(maxp.back().begin(), maxp.back().end());
    }
};