#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> ma(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> ma[i][j] ;
        }
    }
    int target;
    cin >> target;
    int trow = 0;
    int tcol = n - 1;
    while(trow < m && tcol >= 0)
    {
        if(ma[trow][tcol] == target)
        {
            cout << "true" << endl;
            return 0;
        }
        if(ma[trow][tcol] > target)
        {
            tcol -= 1;
        }
        else
        {
            trow += 1;
        }
    }
    cout << "false" << endl;
    return 0;
}