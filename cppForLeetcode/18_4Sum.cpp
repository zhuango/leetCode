#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        set<string> resultStr;
        sort(nums.begin(), nums.end());
        int one = 0;
        int two = 1;
        int thr = 2;
        int fou = 3;

        int tempSum = 0;
        int curSum = 0;
        int old = 0;
        string tempStr = "";
        while (fou < nums.size())
        {
            thr = 2;
            while (thr < fou)
            {
                tempSum = nums[fou] + nums[thr];
                one = 0;
                two = thr - 1;
                while (one < two)
                {
                    curSum = tempSum + nums[one] + nums[two];
                    if (curSum == target)
                    {
                        tempStr = vec2str({nums[one], nums[two], nums[thr], nums[fou]});
                        cout << tempStr << endl;
                        if (resultStr.find(tempStr) == resultStr.end())
                        {
                            result.push_back({nums[one], nums[two], nums[thr], nums[fou]});
                            resultStr.insert(tempStr);
                        }
                        old = nums[one];
                        while (one + 1 < two && nums[one + 1] == old) ++one;
                        old = nums[two];
                        while (two - 1 > one && nums[two - 1] == old) --two;
                    }
                    if (curSum <= target)
                    {
                        one += 1;
                    }
                    else
                    {
                        two -= 1;
                    }
                }
                thr += 1;
            }
            fou += 1;
        }
        return result;
    }
    string vec2str(vector<int> &&a)
    {
        stringstream ss;
        for (int elem: a)
        {
            ss << elem << "_";
        }
        return ss.str();
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {1,0,-1,0,-2,2, 2, -2, 2, -2};
    sol.fourSum(input, 0);
}