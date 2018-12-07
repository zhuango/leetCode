#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void cur(int i, int n, vector<int> &result)
    {
        for(int j = 0; j < 10; ++j)
        {
            int tempi = i * 10 + j;
            if(tempi == 0) continue;
            if(tempi > n)
            {
                break;
            }
            result.push_back(tempi);
            cur(tempi, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        cur(0, n, result);
        return result;
    }
};
int main(void)
{
}