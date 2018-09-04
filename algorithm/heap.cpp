#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> input = {23, 1, 243, 2, 342, 3, 23, 43, 54};
    make_heap(input.begin(), input.end(), greater<int>());
    for(int i : input)
    {
        cout << i << " ";
    }
    cout << endl;

    input.push_back(0);
    push_heap(input.begin(), input.end(), greater<int> ());
    int a = input[0];
    cout << a << endl;

    pop_heap(input.begin(), input.end(), greater<int> ());
    input.pop_back();
    a = input[0];
    cout << a << endl;
    a = input.back();
    cout << a << endl;

    return 0;
}