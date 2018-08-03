#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int temp;
    vector<int> apples;
    bool he = false;
    bool ho = false;
    int sum = 0;
    while(cin >> temp)
    {
        if(temp % 2 == 0) he = true;
        else ho = true;
        sum += temp;
        apples.push_back(temp);
    }
    if(he and ho)
    {
        cout << -1 << endl;
        return 0;
    }
    if(sum % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int ave = sum / n;
    if((ave % 2 == 0) and ho)
    {
        cout << -1 << endl;
        return 0;
    }
    if((ave % 2 == 1) and he)
    {
        cout << -1 << endl;
        return 0;
    }
    
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(apples[i] > ave)
        {
            cnt += (apples[i] - ave) / 2;
        }
    }
    cout << cnt << endl;
}