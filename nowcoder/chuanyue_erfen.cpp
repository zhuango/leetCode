#include <iostream>

using namespace std;

int main(void)
{
    double h;
    cin >> h;

    long i = 0;
    long j = 1e18;
    int result = 0;
    while(i <= j)
    {
        double mid = (i + j) / 2;
        if(mid*(mid+1) <= h)
        {
            i = mid + 1;
            result = mid;
        }
        else
        {
            j = mid - 1;
        }
    }
    cout << result << endl;
    return 0;
}

