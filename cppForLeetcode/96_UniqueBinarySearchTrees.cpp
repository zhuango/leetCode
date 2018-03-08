#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {

        vector<int> memTable;
        memTable.push_back(0);
        memTable.push_back(1);
        for (int i = 1; i <= n; ++i)
        {
            int ss = 0;
            for (int j = 1; j <= i; ++j)
            {
                ss += memTable[j] * memTable[i - j + 1];
            }
            memTable.push_back(ss);
        }
        return *(memTable.end() - 1);
    }
};
