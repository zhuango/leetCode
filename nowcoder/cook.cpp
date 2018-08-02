#include <set>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    set<string> str;
    string s;
    while(cin >> s)
    {
        str.emplace(s);
    }
    cout << str.size() << endl;
}