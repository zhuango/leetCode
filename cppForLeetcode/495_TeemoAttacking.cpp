#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int start = 0;
        int posi = 0;
        int active = timeSeries[0];
        for(int i = 0; i < timeSeries.size(); ++i)
        {
            if (active >= timeSeries[i])
            {
                posi += active - timeSeries[start];
                start = i;
            }
            active = timeSeries[i] + duration;
        }
        return posi + (active - timeSeries[start]);
    }
};