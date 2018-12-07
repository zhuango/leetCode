#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
 
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return (p1.second < p2.second) || (p1.second == p2.second && p1.first > p2.first);
}
 
int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> time(N);
    for (int i = 0; i < N; ++i)
    {
        int s, t;
        cin >> s >> t;
        if (s >= t) t += M;
            time[i] = make_pair(s, t);
    }
    sort(time.begin(), time.end(), cmp);
    int finalRes = 0;
    for (int j = 0; j < N; ++j) //j代表从第j个开始看

    {
        int res = 0;
        int cur0 = time[j].first;
        int cur = cur0;
        for (int i = 0; i < N; ++i)
        {
            if (i + j < N && time[i].first >= cur)
            {
                cur = time[i].second;
                if (cur < cur0 + M)
                    ++res;
                else break;
            }
            if (i + j >= N && time[i].first + M >= cur)
            {
                cur = time[i].second + M;
                if (cur < cur0 + M) ++res;
                else break;
            }
        }
        if (res > finalRes)
        finalRes = res;
    }
    cout << finalRes << endl;
    return 0;
}