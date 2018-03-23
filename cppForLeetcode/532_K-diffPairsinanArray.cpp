#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        for (int a: nums)
        {
            mapping[a] ++ ;
        }
        int count = 0;
        for (auto pair: mapping)
        {
            if((!k && pair.second > 1)||
                k && mapping.count(pair.first + k) > 1) count += 1;
        }

        return count;
    }
};

int main(void)
{
    vector<int> input {1, 3, 1, 5, 4};
    Solution sol;
    int results = sol.findPairs(input, 0);
    cout << results << endl;

    return 0;
}