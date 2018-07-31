#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,H = 1;
    int i = 0;
    int f,c, h;
    vector<int> nodes(1000, 0);    //有效节点的高度
    nodes[0] = 1; // 题目说了至少有一个节点，高度只是是1
    vector<int> childnum(1000, 0); //记录节点的孩子数量
    cin >> n;
    while(--n){
        cin >> f >> c;
        //父节点不存在 或者 父节点已有两个子节点 就跳过
        if(nodes[f]==0 || childnum[f] == 2)
        {
            cout << f << " " << c << endl;
            continue;
        }
        childnum[f] += 1;
        h = nodes[f] + 1;
        nodes[c] = h;
        if(h > H) H = h;
    }
    cout << H;
    return 0;
}
