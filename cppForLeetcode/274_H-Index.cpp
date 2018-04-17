#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int a, int b) {return a > b;});
        map<int, int> table;
        for(int i = 0; i < citations.size(); ++i)
        {
            table[citations[i]] = i + 1;
        }
        int hIndex= 0;
        for(auto &pair : table)
        {
            if(pair.first >= pair.second && pair.second > hIndex)
            {
                hIndex = pair.first;
            }
        }
        return hIndex;
    }
};