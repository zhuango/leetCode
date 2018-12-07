#include<iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n;
    cin >>n;
    int result;
    for(int i = 0; i*i < n; ++i)
    {
        double diamF = sqrt(n-i*i);
        int diam = diamF;
        if(abs(diamF - diam) < 0.000001) result += 4;
    }
    cout << result << endl;
    
    return 0;
}