#include <vector>
#include <iostream>

using namespace std;

int bs(vector<int> &maxs, int len, int m)
{
    int i = 0;
    int j = len;
    while(i < j)
    {
        int mid = (i  + j) / 2;
        if(maxs[mid] <= m)
        {
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }
    return j;
}
int lci(vector<int> &input)
{
    vector<int> dp(input.size());
    dp[0] = input[0];
    int len = 1;
    for(int i = 1; i < input.size(); ++i)
    {
        if(input[i] > dp[len-1])
        {
            dp[len++] = input[i];
        }
        else
        {
            int pos = bs(dp, len-1, input[i]);
            dp[pos] = input[i];
        }
    }
    return len;
}

int main(void)
{
    vector<int> input = {10, 3, 7, 5};
    cout << lci(input) << endl;

}