#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        int end = 0;
        int i = 0;
        for (auto a: nums)
        {
            i = 0;
            end = result.size();
            while (i < end)
            {
                vector<int> temp = result[i];
                temp.push_back(a);
                result.push_back(temp);
                i += 1;
            }
        }
        return result;
    }
};