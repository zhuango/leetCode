#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ori;
    vector<int> tar;
    int left = -1;
    for(int i = 0; i < n; ++i)
    {
        int tem;
        cin >> tem;
        ori.push_back(tem);
        if(tem != 0 && left == -1)
        {
            left = i;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        int tem;
        cin >> tem;
        tar.push_back(tem);
    }

    int step = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        if(ori[i] == tar[i]) continue;
        if(ori[i] > tar[i])
        {
            step += ori[i] - tar[i];
            ori[i - 1] += ori[i] - tar[i];
            ori[i] = tar[i];
        }
        else
        {
            int move = ori[left];
            int cha = tar[i] - ori[i];
            while(move < cha)
            {
                step += ori[left] * (left + i);
                ori[left] = 0;
                left += 1;
                move += ori[left];
            }
            step += (ori[left] - (move - cha)) * (left + i);
            ori[left] = move - cha;
        }
    }
    cout << step << endl;
}
