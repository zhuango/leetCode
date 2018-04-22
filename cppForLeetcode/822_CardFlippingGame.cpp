#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int, vector<int>> counter;
        int count = 0;
        for(int i : fronts)
        {
            counter[i].push_back(count);
            count += 1;
        }
        int result = 0x7fffffff;
        int front;
        int back;
        for(int i = 0; i < fronts.size(); ++i)
        {
            front = fronts[i];
            back = backs[i];

            if(front != back)
            {
                if (counter.count(back) == 0)
                {
                    if (back < result)
                    {
                        result = back;
                    }
                }
                    bool same = false;
                    for(int t : counter[front])
                    {
                        if (t != i && fronts[t] == front && backs[t] == front)
                        {
                            same = true;
                        }
                    }
                    if(!same)
                    {
                        if (front < result)
                        {
                            result = front;
                        }
                    }
                
            }
        }
        if(result == 0x7fffffff) return 0;
        return result;
    }
};

int main(void)
{
    vector<int> input0 = {1,2,4,-1,-1};
    vector<int> input1 = {1,-1,4,1,1};
    // vector<int> input0 = {1,2};
    // vector<int> input1 = {1,1};
    // vector<int> input0 = {1,1};
    // vector<int> input1 = {1,2};
    // vector<int> input0 = {1,1};
    // vector<int> input1 = {2,2};
    Solution sol;
    cout << sol.flipgame(input0,input1) << endl;
}