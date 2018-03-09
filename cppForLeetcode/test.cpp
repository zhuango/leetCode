#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
    // stringstream ss("liu zhuang liuzhua ss");
    string s = "";
    // ss >> s;
    // cout << s << endl;
    // ss >> s;
    // cout << s << endl;
    // ss >> s;
    // cout << s << endl;
    

    stringstream ss1;
    ss1 << "DDDDDDD" ;
    ss1 << "DDDDDDD" << "EE" ;
    // int a = 0;
    // ss1 >> a;
    // cout << a << endl;
    cout << ss1.str() << endl;
    while (ss1 >> s)
    {
        cout << s << endl;
    }
    // cout << isdigit(s[0]) << endl;
    return 0;
}