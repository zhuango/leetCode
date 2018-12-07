#include <iostream>
#include <vector>

using namespace std;
long long interv = 1000000007;

int main(void)
{
    long long pos;
    cin >> pos;
    long long step = 100001;
    for(long long x = pos, i = 0; i < 3; ++i, x = (4 * x + 3) % interv)
    {
        long long tempStep = 100001;
        if(x % interv == 0)
        {
            tempStep = i;
        }
        else
        {
            long long tempx = x;
            for(int j = 0; j < 100000 - i; ++j)
            {
                
                tempx = (8*tempx + 7) % interv;
                if(tempx % interv == 0)
                {
                    tempStep = i + j + 1;
                    break;
                }
            }
        }
        if(tempStep < step)
        {
            step = tempStep;
        }
    }
    if(step == 100001) cout << -1 << endl;
    else cout << step << endl;
    
    return 0;
}