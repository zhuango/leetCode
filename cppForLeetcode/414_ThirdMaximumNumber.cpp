#include <iostream>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> queue;
        for(auto a : nums)
        {
            queue.push(a);
        }
        int max = queue.top();
        queue.pop();
        int prev = max;
        int count = 0;
        while(!queue.empty() && count < 2)
        {
            if (queue.top() == prev)
            {
                queue.top();
            }
            else
            {
                count += 1;
                prev = queue.top();
            }
            queue.pop();
        }
        cout << max << endl;

    }
};

int main(void)
{
    priority_queue<int> queue;
    queue.push(12);
    queue.push(2);
    queue.push(1);
    cout << queue.top() << endl;
}