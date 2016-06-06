#include "Common.h"

vector<int> countBits(int num)
{
    int tmpnum = 1;
    unsigned int count = 0;
    vector<int> result;
    result.push_back(0);
    while(tmpnum * 2 <= num)
    {
        count = result.size();
        for(unsigned int i = 0; i < count; ++i)
        {
            result.push_back(result[i] + 1);
        }
        tmpnum = tmpnum * 2;
    }
    tmpnum = num + 1 - tmpnum;
    for(int i = 0; i < tmpnum; ++i)
    {
        result.push_back(result[i] + 1);
    }
    return result;
}


int main(void)
{
    vector<int> result = countBits(4);
    for(vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << (*iter) << " ";
    }
    cout << endl;
}