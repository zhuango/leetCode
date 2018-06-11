#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string S;
    cin >> S;
    
    int rest = 0;
    rest = a % b;
    unordered_map<int, int> mapping;
    string num = "";
    while(mapping.count(rest) == 0 && rest != 0)
    {
        int d = rest * 10;
        mapping[rest] = mapping.size();
        num.push_back(d / b + '0');
        rest = d % b;
    }
    if(rest != 0)
    {
        string xunhuanjie = num.substr(mapping[rest]);
        int count = 0;
        while(count * xunhuanjie.size() <= S.size())
        {
            num = num + xunhuanjie;
            count += 1;
        }
    }
    else
    {
        string zeros = "";
        for(int i = 0; i < S.size(); ++i)
        {
            zeros.push_back('0');
        }
        num = num + zeros;
    }
    cout << num << endl;
    size_t ret = num.find(S);
    if (ret < num.size())
    {
        cout << ret + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}