#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int max = 0;
        int m = arr.size();
        for (int i = 0; i < m; ++i)
        {
            if (arr[i] < max)
            {
                max = arr[i];
            }
            if (i == max)
            {
                count ++;
            }
        }
        return count;
    }
};