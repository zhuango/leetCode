#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0) return 0;
        vector<vector<int>> maxp(costs.size(), vector<int> (3, 0x7fffffff));
        for(int i = 0; i < costs[0].size(); ++i)
        {
            maxp[0][i] = costs[0][i];
        }
        for(int i = 1; i < costs.size(); ++i)
        {
            maxp[i][0] = min(maxp[i-1][1], maxp[i-1][2]) + costs[i][0];
            maxp[i][1] = min(maxp[i-1][0], maxp[i-1][2]) + costs[i][1];
            maxp[i][2] = min(maxp[i-1][0], maxp[i-1][1]) + costs[i][2];
        }
        int n = costs.size() - 1;
        return min(maxp[n][0], min(maxp[n][1], maxp[n][2]));
    }
};