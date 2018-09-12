#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mapping;
        unordered_set<int> sign;
        unordered_set<int> numss;
        for(int i : nums)
        {
            numss.insert(i);
        }
        int flag = 0;
        for(int i : nums)
        {
            if(sign.find(i) != sign.end())
            {
                continue;
            }
            int tempi = i;
            while(numss.find(tempi) != numss.end())
            {
                mapping[flag] += 1;
                sign.insert(tempi);
                tempi ++;
            }
            i -= 1;
            while(numss.find(i) != numss.end())
            {
                mapping[flag] += 1;
                sign.insert(i);
                i--;
            }
            flag++;
        }
        int min = 0;
        for(auto &pair : mapping)
        {
            if(pair.second > min)
            {
                min = pair.second;
            }
        }
        return min;
    }
};

int main(void)
{
    vector<int> input = {3, 2};
    Solution sol;
    cout << sol.longestConsecutive(input) << endl;
}