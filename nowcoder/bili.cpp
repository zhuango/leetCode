#include <iostream>
#include <string>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int getnextNumber(const string &s, unsigned int &index)
{
    int num =0 ;
    while(index < s.size() && isdigit(s[index]))
    {
        num = num * 10 + s[index] - '0';
        index ++;
    }
    return num;
}

int compareVersionNumber(const string& x, const string& y) {
    unsigned int indexx = 0;
    unsigned int indexy = 0;
    while(indexx < x.size() && indexy < y.size())
    {
        int verx = getnextNumber(x, indexx);
        int very = getnextNumber(y, indexy);
        if(verx > very) return 1;
        if(verx < very) return -1;
        indexx += 1;
        indexy += 1;
    }
    if(indexx >= x.size() && indexy >= y.size()) return 0;
    if(indexx < x.size()) return 1;
    if(indexy < y.size()) return -1;
}
/******************************结束写代码******************************/


int main() {
    string x;
    string y;
    cin >> x >> y;
    cout << compareVersionNumber(x, y);
    return 0;

}
