#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    int index = 2;
    while (fib.back() < n)
    {
        fib.push_back(fib[index-1] + fib[index -2]);
        index ++;
    }
    if(fib[index-1] - n < n - fib[index - 2])
    {
        cout << fib[index-1] - n << endl;
    }
    else
    {
        cout << n - fib[index - 2] << endl;
    }
}