#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a;
    cin >> b;
    int jinwei = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int lengtha = a.size();
    int lengthb = b.size();
    if(lengtha > lengthb)
    {
        for(int i = 0; i < lengtha - lengthb; ++i)
        {
            b.push_back('a');
        }
    }
    else
    {
        for(int i = 0; i < lengthb - lengtha; ++i)
        {
            a.push_back('a');
        }
    }
    int index = 0;
    string result = "";
    while(index < a.size())
    {
        int temp = a[index] - 'a' + b[index] - 'a' + jinwei;
        jinwei = temp / 26;
        temp = temp % 26;
        result.push_back(temp + 'a');
        index += 1;
    }
    if(jinwei != 0) result.push_back(jinwei + 'a');
    reverse(result.begin(), result.end());
    
    cout << result<< endl;
    return 0;
}