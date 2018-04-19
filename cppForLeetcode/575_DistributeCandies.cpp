#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int length = candies.size() / 2;
        unordered_map<int, bool> table;
        for(int i = 0; i < candies.size(); ++i)
        {
            if(table[candies[i]])
            {
                length -= 1;
            }
            else table[candies[i]] = true;
        }
        if (length <= 0) return table.size();
        else return table.size() - length;
    }
};