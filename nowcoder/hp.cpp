#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int hp, nor, buf;
    cin >> hp >> nor >> buf;
    int twice = nor * 2;
    int step = 0;
    while(hp > 0)
    {
        if(buf > twice && hp > nor)
        {
            int in = (hp - nor) / buf;
            step += in * 2;
            hp -= in * buf;
        }
        else
        {
            step += 1;
            hp -= nor;
        }
    }
    cout << step << endl;

    return 0;
}
