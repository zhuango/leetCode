#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i = 0;
        int result = 0;
        int nextOne = 0;
        int nextTwo = 0;
        for(i = cost.size() - 1; i >= 0; --i)
        {
            result = min(nextOne, nextTwo) + cost[i];
            nextTwo = nextOne;
            nextOne = result;
        }
        return min(nextTwo, nextOne);
    }
};