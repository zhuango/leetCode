#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> count;
        int n = wall.size();
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = 0; j < wall[i].size() -1 ; ++j)
            {
                sum += wall[i][j];
                count[sum] += 1;
            }
        }
        int mx = 0;
        for(auto &pair : count)
        {
            mx = max(mx, pair.second);
        }
        return n - mx;
    }
};