#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int count = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            pair<int, int> pair1 = points[i];
            unordered_map<int, int> mem;
            for(int j = 0; j < points.size(); ++j)
            {
                pair<int, int> pair2 = points[j];
                int f = abs(pair1.first - pair2.first);
                int s = abs(pair1.second - pair2.second);
                int distance = f * f + s * s;
                if (mem[distance] >= 1)
                {
                    mem[distance] *= mem[distance] + 1;
                }
                else
                {
                    mem[distance] = 1;
                }
            }
            for(auto &pair : mem)
            {
                if (pair.second > 1)
                {
                    count += pair.second;
                }
            }
        }
        return count;
    }
};