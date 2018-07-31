#include <iostream>
#include <vector>

using namespace std;

int high(vector<vector<int>> &tree, long root)
{
    long maxHigh = 0;
    for(long i = 0; i < tree[root].size(); ++i)
    {
        long temph = high(tree, tree[root][i]);
        if(temph > maxHigh)
        {
            maxHigh = temph;
        }
    } 
    
    return maxHigh + 1;
}
int main(void)
{
    long n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<bool> children(n, false);
    vector<bool> fathers (n, false);
    fathers[0] = true;
    long father, child;
    while(cin >> father >> child)
    {
        if(tree[father].size() == 2 || fathers[father] == false)
        {
            continue;
        }
        tree[father].push_back(child);
        children[child] = true;
        fathers[child] = true;
    }
    long root = 0;
    for(long i = 0; i < n; ++i)
    {
        if(!children[i])
        {
            root = i;
            break;
        }
    }
    cout << high(tree, root) << endl;
    return 0;
}