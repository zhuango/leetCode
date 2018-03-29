#include<vector>
#include <map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> countTable;
        map<int, int> startTable;
        map<int, int> endTable;
        int curNum;
        for(int i = 0; i < nums.size(); ++i)
        {
            curNum = nums[i];
            if (countTable[curNum] == 0)
            {
                startTable[curNum] = i;
            }
            countTable[curNum] += 1;
            endTable[curNum] = i;
        }
        int maxCount = 0;
        int num = nums[0];
        for(auto &pair : countTable)
        {
            if (pair.second > maxCount)
            {
                maxCount = pair.second;
                num = pair.first;
            }
        }
        int minLength = nums.size();
        int curLength = 0;
        for (auto &pair: countTable)
        {
            if (pair.second == maxCount)
            {
                curLength = endTable[pair.first] - startTable[pair.first] + 1;
                if (curLength < minLength)
                {
                    minLength = curLength;
                }
            }
        }
        return minLength;
    }
};