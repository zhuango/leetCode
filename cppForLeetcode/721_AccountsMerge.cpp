#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> results;
        unordered_map<string, vector<int>> email2Acc;
        // construt emial -> account id list.
        for(int i = 0; i < accounts.size(); ++i)
        {
            vector<string> &acc = accounts[i];
            for(int j = 1; j < acc.size(); ++j)
            {
                email2Acc[acc[j]].push_back(i);
            }
        }
        unordered_map<string, bool> visited;
        for(auto &pair : email2Acc)
        {
            if(!visited[pair.first])
            {
                vector<string> emails;
                emails.push_back(accounts[pair.second[0]][0]);
                dfs(email2Acc, accounts, visited, pair.first, emails);
                sort(emails.begin() + 1, emails.end());
                results.push_back(emails);
            }
        }
        return results;
    }
    void dfs(unordered_map<string, vector<int>> &email2Acc, vector<vector<string>> &accounts, unordered_map<string, bool> &visited, string mail, vector<string> &email)
    {
        if(visited[mail]) return;
        visited[mail] = true;
        email.push_back(mail);
        for(int i : email2Acc[mail])
        {
            for(int j = 1 ; j < accounts[i].size(); ++j)
            {
                if(visited[accounts[i][j]]) continue;
                else dfs(email2Acc, accounts, visited, accounts[i][j], email);
            }
        }
    }
};

int main(void)
{
    vector<vector<string>> input = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    Solution sol;
    for (auto &as : sol.accountsMerge(input))
    {
        for(string &s : as)
        {
            cout << s << " " ;
        }
        cout << endl;
    }
}