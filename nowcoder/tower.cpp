#include <iostream>
#include <vector>
#include <map>

using namespace std;

pair<int, int> argmax(vector<int> &a)
{
    int pos = 0;
    int res = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] > res)
        {
            res = a[i];
            pos = i;
        }
    }
    return {res, pos};
}

pair<int, int> argmin(vector<int> &a)
{
    int pos = 0;
    int res = 0x7fffffff;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] < res)
        {
            res = a[i];
            pos = i;
        }
    }
    return {res, pos};
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> high(n, 0);
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> high[i];
        sum += high[i];
    }
    int average = sum / n;
    int rest = sum % n;

    int step = 0;
    vector<pair<int, int>> move;
    pair<int, int> ma;
    pair<int, int> mi;
    for(int i = 0; i < k; ++i)
    {
        ma = argmax(high);
        mi = argmin(high);
        if(mi.first < average || ma.first > average + 1)
        {
            high[mi.second] += 1;
            high[ma.second] -= 1;
            move.push_back({ma.second + 1, mi.second + 1});
            step ++;
        }
        else
        {
            break;
        }
    }
    ma = argmax(high);
    mi = argmin(high);
    cout << ma.first - mi.first << " " << step << endl;
    for(auto &p : move)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}