#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int n = height.size();
        int water = 0;
        int maxLeft = 0;
        int maxright = 0;
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    water += maxLeft - height[left];
                }
                left ++;
            }
            else
            {
                if(height[right] >= maxright)
                {
                    maxright = height[right];
                }
                else
                {
                    water += maxright- height[right];
                }
                right --;
            }
        }
        return water;
    }
};