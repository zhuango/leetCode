#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> movies;
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        movies.push_back(s);
    }
    unordered_map<char, vector<int>> posi;
    posi['@'] = {0, 0};
    posi['!'] = {0, 0};
    posi[':'] = {0, 0};
    posi['A'] = {0, 1};
    posi['B'] = {0, 1};
    posi['C'] = {0, 1};
    posi['D'] = {0, 2};
    posi['E'] = {0, 2};
    posi['F'] = {0, 2};
    posi['G'] = {1, 0};
    posi['H'] = {1, 0};
    posi['I'] = {1, 0};
    posi['J'] = {1, 1};
    posi['K'] = {1, 1};
    posi['L'] = {1, 1};
    posi['M'] = {1, 2};
    posi['N'] = {1, 2};
    posi['O'] = {1, 2};
    posi['P'] = {2, 0};
    posi['Q'] = {2, 0};
    posi['R'] = {2, 0};
    posi['S'] = {2, 0};
    posi['T'] = {2, 1};
    posi['U'] = {2, 1};
    posi['V'] = {2, 1};
    posi['W'] = {2, 2};
    posi['X'] = {2, 2};
    posi['Y'] = {2, 2};
    posi['Z'] = {2, 2};
    for(int i = 0; i < n; ++i)
    {
        int step = 0;
        int r = 0, c = 0;
        for(char ch : movies[i])
        {
            step += abs(r - posi[ch][0]) + abs(c - posi[ch][1]);
            r = posi[ch][0];
            c = posi[ch][1];
        }
        cout << step << endl;
    }
}