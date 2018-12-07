#include <iostream>
#include <vector>

using namespace std;

void cur(vector<int> num, int k)
{
    if(k >= num.size())
    {
        for(int i : num)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int temp = 0;
    for(int i = k; i < num.size(); ++i)
    {
        temp = num[k];
        num[k] = num[i];
        num[i] = temp;

        cur(num, k + 1);

        num[i] = num[k];
        num[k] = temp;
    }
}

int main(void)
{
    int n = 5;
    vector<int> input = {1, 2, 3, 4, 5};
    cur(input, 0);
}