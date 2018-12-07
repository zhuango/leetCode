#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int getnum(string &s, int &index)
{
    int re = 0;
    while(index < s.size() && s[index] >= '0' && s[index] <= '9')
    {
        re = re * 10 + s[index] - '0';
        index += 1;
    }
    return re;
}

int main(void)
{
    string s;
    cin >> s;
    int i = 0;
    vector<pair<string, int>> strs;
    while(i < s.size())
    {
        int length = 0;
        int oldi = i;
        while(!isdigit(s[i]))
        {
            i++;
            length ++;
        }
        strs.push_back({s.substr(oldi, length), getnum(s, i)});
    }
    sort(strs.begin(), strs.end(), [](pair<string, int> &a, pair<string, int> &b)
    {
        if(a.second < b.second)
            return true;
        else if(a.second > b.second)
            return false;
        if(a.first.size() < b.first.size())
            return true;
        else if(a.first.size() > b.first.size())
            return false;
        return a.first < b.first;
    });
    string result = "";
    for(auto &p : strs)
    {
        for(int i = 0; i < p.second; ++i)
        {
            result += p.first;
        }
    }
    cout << result << endl;
    return 0;
}