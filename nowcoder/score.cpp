#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long teamScore = 0;
void getScore(vector<vector<long long>> &score, long long index, long long sa, long long sb, long long ts)
{
    if(sa == sb && ts > teamScore)
    {
        teamScore = ts;
    }
    if(index >= score.size())
    {
        return;
    }
    ts += score[index][1];
    sa += score[index][0];
    getScore(score, index + 1, sa, sb, ts);
    sa -= score[index][0];
    
    sb += score[index][0];
    getScore(score, index + 1, sa, sb, ts);
    sb -= score[index][0];
    ts -= score[index][1];

    getScore(score, index + 1, sa, sb, ts);
}

int main(void)
{
    int n;
    cin >> n;
    vector<vector<long long>> score(n, vector<long long>(2, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> score[i][0];
        cin >> score[i][1];
    }
    long long sa= 0;
    long long sb = 0;
    getScore(score, 0, sa, sb, 0);
    cout << teamScore << endl;
    return 0;
}