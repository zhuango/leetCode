/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 *
 * https://leetcode.com/problems/broken-calculator/description/
 *
 * algorithms
 * Medium (37.43%)
 * Total Accepted:    3.6K
 * Total Submissions: 9.6K
 * Testcase Example:  '2\n3'
 *
 * On a broken calculator that has a number showing on its display, we can
 * perform two operations:
 * 
 * 
 * Double: Multiply the number on the display by 2, or;
 * Decrement: Subtract 1 from the number on the display.
 * 
 * 
 * Initially, the calculator is displaying the number X.
 * 
 * Return the minimum number of operations needed to display the number Y.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: X = 2, Y = 3
 * Output: 2
 * Explanation: Use double operation and then decrement operation {2 -> 4 ->
 * 3}.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: X = 5, Y = 8
 * Output: 2
 * Explanation: Use decrement and then double {5 -> 4 -> 8}.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: X = 3, Y = 10
 * Output: 3
 * Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: X = 1024, Y = 1
 * Output: 1023
 * Explanation: Use decrement operations 1023 times.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= X <= 10^9
 * 1 <= Y <= 10^9
 * 
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> bin(int x)
    {
        stack<int> bi;
        while(x)
        {
            bi.push(x % 2);
            x = x / 2;
        }
        return bi;
    }
    int brokenCalc(int X, int Y) {
        int step = 0;
        if (X >= Y)
        {
            return X - Y;
        }

        int oriStep = 0;
        while (X < Y)
        {
            X *= 2;
            oriStep += 1;
        }
        int diff = X - Y;
        cout << diff << endl;
        cout << X << endl;
        if (diff != 0)
        {
            stack<int> binx = this->bin(diff);
            while (!binx.empty())
            {
                int i = binx.top();
                binx.pop();
                if (i == 1)
                {
                    oriStep += 1;
                }
            }
        }

        return oriStep;
    }
};

int main(void)
{
    Solution sol = Solution();
    int result = sol.brokenCalc(68, 71);
    cout << result << endl;
    return 0;
}
