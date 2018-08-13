#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long getCount(vector<vector<long long>> &funs, vector<vector<bool>> &tag, int i, int j)
{
    long long count = 0;
    int m = funs.size();
    int n = funs[0].size();
    if(i >= m || j >= n || i < 0 || j < 0) return 0;
    if(funs[i][j] == 1 && !tag[i][j])
    {
        count ++ ;
        tag[i][j] = true;
    }
    else return 0;
    
    count += getCount(funs, tag, i + 1, j);
    count += getCount(funs, tag, i, j + 1);
    count += getCount(funs, tag, i - 1, j);
    count += getCount(funs, tag, i, j - 1);
    count += getCount(funs, tag, i + 1, j + 1);
    count += getCount(funs, tag, i - 1, j - 1);
    count += getCount(funs, tag, i + 1, j - 1);
    count += getCount(funs, tag, i - 1, j + 1);
    return count;
}

int main(void)
{
    long long m, n;
    string s;
    cin >> s;
    int pos = s.find(',');
    m = stoi(s.substr(0, pos));
    n = stoi(s.substr(pos+1));
    vector<vector<long long>> funs(m, vector<long long>(n, 0));
    vector<vector<bool>> tag(m, vector<bool>(n, false));
    for(int i = 0; i < m; ++i)
    {
        cin >> s;
        for(int j = 0; j < n; ++j)
        {
            funs[i][j] = stoi(s.substr(0, 1));
            if(j != n - 1) s = s.substr(s.find(',')+1);
        }
    }
    long long result = 0;
    long long count = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            long long temp = 0;
            if(funs[i][j]&&!tag[i][j])
            {
                count ++;
                temp = getCount(funs, tag, i, j);
                if(temp > result)
                {
                    result = temp;
                }
            }
        }
    }
    cout << count << "," << result << endl;
    return 0;
}