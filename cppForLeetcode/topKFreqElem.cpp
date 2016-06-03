#include "Common.h"
bool comFunc(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second);
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    map<int, int> counter;
    vector<int> result(k, 0);
    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
    {
        map<int,int>::iterator elem = counter.find(*iter);
        if(elem == counter.end())
        {
            counter.insert(pair<int,int>(*iter, 1));
        }
        else
        {
            elem->second += 1;
        }
    }
    vector<pair<int, int> > tmp;
    for(map<int, int>::iterator iter = counter.begin(); iter != counter.end(); ++iter)
    {
        tmp.push_back(pair<int,int>(iter->first, iter->second));
    }
    
    sort(tmp.begin(), tmp.end(), comFunc);
    vector<pair<int, int> >::iterator index=tmp.begin();
    for(unsigned int i = 0; i < k; ++i)
    {
        result[i] = (*index).first;
        index++;
    }
    return result;
}

int main(void)
{
    int arrays[] = {1,1,1,2,2,3};
    vector<int> input(arrays, arrays + 6);
    vector<int> result = topKFrequent(input, 2);
    for(vector<int>::iterator iter =result.begin(); iter != result.end(); ++iter)
    {
        cout << (*iter) << " ";
    }
    cout << endl;
    return 0;
}