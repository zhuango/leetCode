#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    string a, b;
    cin >>a >>b;
    if(a.size() != b.size())
    {
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    vector<int> dict(26, 0);
    bool hastwo = false;
    for(int i = 0; i < a.size(); ++i)
    {
        dict[a[i] - 'a'] += 1;
        if(dict[a[i] - 'a'] >= 2)
        {
            hastwo = true;
        }
        if(a[i] != b[i])
        {
            count += 1;
            if(count > 2)
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if(count == 1)
        cout << 0 << endl;
    else if(count == 2)
        cout << 1 << endl;
    else if(count == 0 && hastwo)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}