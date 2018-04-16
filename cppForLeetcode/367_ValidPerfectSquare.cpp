
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        int end = 46341;
        int middle = 0;
        int square = 0;
        int oldStart = -1;
        int oldEnd = -1;
        while(start <= end)
        {
            middle = start + (end - start) / 2;
            square = middle * middle;
            if(square > num || square < 0)
            {
                end = middle;
            }
            else if(square < num)
            {
                start = middle;
            }
            else return true;
            if (oldStart == start && oldEnd == end)
            {
                return false;
            }
            oldStart = start;
            oldEnd = end;
        }
        return false;
    }
};


int main(void)
{
    Solution sol;
    cout << sol.isPerfectSquare(0) << endl;
    cout << sol.isPerfectSquare(1) << endl;
    cout << sol.isPerfectSquare(2) << endl;
    cout << sol.isPerfectSquare(3) << endl;
    cout << sol.isPerfectSquare(4) << endl;
    cout << sol.isPerfectSquare(5) << endl;
    cout << sol.isPerfectSquare(6) << endl;
    cout << sol.isPerfectSquare(7) << endl;
    cout << sol.isPerfectSquare(8) << endl;
    cout << sol.isPerfectSquare(9) << endl;
    cout << sol.isPerfectSquare(10) << endl;
    cout << sol.isPerfectSquare(11) << endl;
    cout << sol.isPerfectSquare(12) << endl;
    cout << sol.isPerfectSquare(13) << endl;
    cout << sol.isPerfectSquare(16) << endl;
    cout << sol.isPerfectSquare(121) << endl;
    cout << sol.isPerfectSquare(808201) << endl;
}