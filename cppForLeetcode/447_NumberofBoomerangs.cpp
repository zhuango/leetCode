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
                int f = pair1.first - pair2.first;
                int s = pair1.second - pair2.second;
                int distance = f * f + s * s;
                mem[distance] += 1;
            }
            for(auto &pair : mem)
            {
                count += pair.second * (pair.second - 1);
            }
        }
        return count;
    }
};