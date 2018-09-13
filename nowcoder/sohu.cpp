#include <iostream>

using namespace std;


int main(void)
{
    int target;
    cin >> target;
    int cur = 0;
    int step = 0;
    target = abs(target);
    while(cur < target)
    {
        step += 1;
        cur += step;
    }
        
    while((cur - target) % 2 != 0)
    {
        step += 1;
        cur += step;
    }
    cout << step << endl;
    return 0;
}
