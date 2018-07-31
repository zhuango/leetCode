#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    string a = "1234";
    string b = "12";
    cout << (a > b) << endl;
    int n;
    cin >> n;
    vector<string> numbers;
    string temp = "";
    while(cin >> temp)
    {
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end(), [](string &a, string &b){return a+b > b+a;});
    string number = "";
    for(string &s : numbers)
    {
        number += s;
    }
    cout << number << endl;
    return 0;
}