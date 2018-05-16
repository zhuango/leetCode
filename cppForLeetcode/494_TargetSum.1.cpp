#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        unordered_map<int, int> sumCount;
        sumCount[nums[0]] += 1;
        sumCount[-nums[0]] += 1;
        for(int j = 1; j < nums.size(); ++j)
        {
            int i = nums[j];
            unordered_map<int,int> keys;
            for(auto &pair : sumCount)
            {
                int add = i + pair.first;
                int sub = -i + pair.first;
                keys[add] += pair.second;
                keys[sub] += pair.second;
            }
            sumCount.swap(keys);
        }
        return sumCount[S];
    }
};
int main(void)
{
    map<int, int> sumCount;
    sumCount[0] = 100;
    sumCount[1] = 1002;
    for(auto &pair : sumCount)
    {
        cout << "DDDDDDDDDDDD" << endl;
        sumCount[3] = 100;
    }
}