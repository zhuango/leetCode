#include <map>
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N >= 5551)
        {
            return 1;
        }
        return calProb(make_pair(N, N));
    }
    double calProb(pair<int, int> pai)
    {
        int a = pai.first;
        int b = pai.second;
        if (a <= 0 && b <= 0)
        {
            return 0.5;
        }
        if (a <= 0)
        {
            return 1;
        }
        if(b <= 0)
        {
            return 0;
        }
        if (table.find(pai) != table.end())
        {
            return table[pai];
        }
        table[pai] = 0.25 * (calProb(make_pair(a - 100, b)) + calProb(make_pair(a - 75, b - 25)) + calProb(make_pair(a - 50, b - 50)) + calProb(make_pair(a - 25, b - 75)));
        return table[pai];
    }
    private:
    map<pair<int, int>, double> table;
};