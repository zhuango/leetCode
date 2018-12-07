#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> input(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    int i = 0;
    int j = n - 1;
    int opeC = 0;
    while(i < j)
    {
        if(input[i] == input[j])
        {
            i++;
            j--;
            continue;
        }
        if(input[i] < input[j])
        {
            input[i+1] += input[i];
            i++;
            opeC += 1;
        }
        else
        {
            input[j-1] += input[j];
            j--;
            opeC += 1;
        }
    }
    cout << opeC << endl;
}