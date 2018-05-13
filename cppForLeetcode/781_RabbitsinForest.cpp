#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> counts;
        for(int i : answers)
        {
            counts[i] += 1;
        }
        int count =0;
        for(auto &pair : counts)
        {
            int group = pair.first + 1;
            count += pair.second / group * group + (pair.second % group ? group : 0);
        }
        return count;
    }
};

int main(void)
{
    vector<int> input = {1,1, 1};
    Solution sol;
    cout << sol.numRabbits(input) << endl;

}