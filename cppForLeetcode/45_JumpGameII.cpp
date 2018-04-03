#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> table(nums.size(), n);
        table[n-1] = 0;
        int index;
        int j;
        for(index = n - 2; index >= 0; --index)
        {
            for(j = index + 1; j < n && j <= index + nums[index]; ++j)
            {
                if (table[index] > table[j])
                {
                    table[index] = table[j];
                }
            }
            table[index] += 1;
            cout << table[index] << " ";
        }
        cout << endl;
        return table[0];
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {2,1,3,1,4};
    cout << sol.jump(input) << endl;
}