#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        vector<int> mapping(71, -1);
        int index = temperatures.size() - 1;
        int max = 0;
        for(auto iter = temperatures.rbegin(); iter != temperatures.rend(); ++iter)
        {
            int dis = temperatures.size();
            for(int i = *iter; i <= max; ++i)
            {
                if(mapping[i - 30] >= 0 && mapping[i - 30] - index < dis)
                {
                    dis = mapping[i - 30] - index;
                }
            }
            mapping[*iter-30] = index;
            if (dis == temperatures.size()) result[index] = 0;
            else result[index] = dis;

            if(*iter > max) max = *iter;
            index -= 1;
        }
        return result;
    }
};