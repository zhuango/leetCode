#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;

    vector<bool> di(26, false);
    for(char chara : a)
    {
        di[chara-'A'] = true;
    }
    bool include = true;
    for(char charb : b)
    {
        if(!di[charb-'A'])
        {
            include = false;
            break;
        }
    }
    if(include) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}