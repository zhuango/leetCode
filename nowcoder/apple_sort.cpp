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
    
    sort(apples.begin(), apples.end(), [](int a, int b){return a > b;});
    int i = 0;
    int j = n-1;
    int cnt = 0;
    while(i < j)
    {
        while(apples[j] < ave && apples[i] > ave)
        {
            apples[j] += 2;
            apples[i] -= 2;
            cnt += 1;
        }
        if(apples[i] == ave)
        {
            i += 1;
        }
        if(apples[j] == ave)
        {
            j -= 1;
        }
    }
    cout << cnt << endl;
}