#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recur(vector<int> &numbers, int m, int s, int index, int &count)
{
    int n = numbers.size();
    int old = numbers[index] - 1;
    for(int i = index; i < n; ++i)
    {
        if(numbers[i] == old) continue;
        old = numbers[i];
        m *= numbers[i];
        s += numbers[i];
        if(m < s) count += 1;
        else if(numbers[i] != 1) break;
        recur(numbers, m, s, i + 1, count);
        m /= numbers[i];
        s -= numbers[i];
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> numbers(n, 0);
    long mul;
    long sss;
    for(int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int count =0;
    recur(numbers, 1, 0, 0, count);
    cout << count << endl;
    
    return 0;
}