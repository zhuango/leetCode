#include"Common.h"
string reversed(string str)
{
    string result(str);
    int maxIndex = str.size() - 1;
    for(int i = maxIndex; i>=0; --i)
    {
        cout << "SDFSDF" << endl;
        result[maxIndex - i] = str[i];
        cout << str[i];
    }
    return result;
}

int main(void)
{
    string s ="lizhuang";
    cout << reversed(s) << endl;
    return 0;
}