#include <vector>
#include <queue>
#include <iostream>

using namespace std;


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        auto a = [](int a, int b) { return a > b; };
        typedef priority_queue<int, vector<int>, decltype(a)> mqueue;
        priority_queue<int> maxqueue;
        maxqueue.push(0x80000000);
        mqueue minqueue(a);
        minqueue.push(0x7fffffff);

        vector<int> result;
        bool even = false;
        for(int n : nums)
        {
            if(even)
            {
                if(n < maxqueue.top())
                {
                    maxqueue.push(n);
                    minqueue.push(maxqueue.top());
                    maxqueue.pop();
                }
                else minqueue.push(n);
                even = false;
            }
            else
            {
                if(n > minqueue.top())
                {
                    minqueue.push(n);
                    maxqueue.push(minqueue.top());
                    minqueue.pop();
                }
                else maxqueue.push(n);
                even = true;
            }
            result.push_back(maxqueue.top());
        }
        return result;
    }
};

int main(void)
{
    vector<int> input = {1,2,3,4,5};
    Solution sol;
    for (int i : sol.medianII(input))
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
        
}