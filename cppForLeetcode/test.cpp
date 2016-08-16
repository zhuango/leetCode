#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    vector<int> s;
    s.push_back(10);
    s.push_back(1000);
    s.erase(s.end() - 1);
    cout << s[0] << endl;
    cout << s.size() << endl;
}