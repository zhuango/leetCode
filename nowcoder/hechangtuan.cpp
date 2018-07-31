#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int k;
    int d;
    vector<int> power;
    cin >> n;
    int temp = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> temp;
        power.push_back(temp);
    }
    cin >> k >> d;
    if (d >= n)
    {
        sort(power.begin(), power.end(), [](int a, int b){return a > b;});
        int result = 1;
        while(k)
        {
            k -= 1;
            result *= power[k];
        }
        cout << result << endl;
        return 0;
    }
    
}