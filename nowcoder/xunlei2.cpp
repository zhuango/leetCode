#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int main(void)
{
    vector<int> a;
    vector<int> b;
    int temp;
    char c;
    while(cin >> temp)
    {
        a.push_back(temp);
        cin >> c;
        if(c == '-') break;
    }
    while(cin >> temp)
    {
        b.push_back(temp);
        cin >> c;
        if(c == ':') break;
    }
    int k;
    cin >> k;

    sort(a.begin(), a.end(), [](int ta, int tb){return ta > tb;});
    sort(b.begin(), b.end(), [](int ta, int tb){return ta > tb;});

    auto comp = [&](const vector<int>& a, const vector<int>& b) {
        return a.back() < b.back();
    };
    typedef priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq_t;
    pq_t pq(comp);
    for(int i = 0; i < b.size(); ++i)
    {
        pq.push({i, 0, b[i] + a[0]});
    }

    int count = 0;
    stringstream ss;
    while(!pq.empty())
    {
        const vector<int> &curMax = pq.top();
        int ib = curMax[0];
        int ia = curMax[1];
        pq.pop();
        int temp = 0;
        int i = 0;
        for(i = ia; i < a.size(); ++i)
        {
            temp = b[ib] + a[i];
            if(temp >= pq.top()[2])
            {
                ss << temp << ',';
                count += 1;
                if(count == k)
                {
                    break;
                }
            }
            else
            {
                pq.push({ib, i, temp});
                break;
            }
        }
        if(count == k) break;
    }
    string result = ss.str();
    cout << result.substr(0, result.size() - 1) << endl;
    return 0;
}