#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int start = 0;
        int end = -1;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (i <= end && arr[i] <= end)
            {
                continue;
            }
            else if (i > end)
            {
                count += 1;
                start = i;
                end = arr[start];
            }
            else if (arr[i] > end)
            {
                end = arr[i];
            }
        }
        return count;
    }
};