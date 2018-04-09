#include <string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int real0 = 0;
        int real1 = 0;
        int xu0 = 0;
        int xu1 = 0;
        int sign = 1;
        getRealAndXu(a, real0, xu0);
        getRealAndXu(a, real1, xu1);
        int real = real0 * real1 - xu0 * xu1;
        int xu = real0 * xu1 + real1 * xu0;
        return to_string(real) + "+" + to_string(xu) + "i";
    }
    void getRealAndXu(string a, int &real, int &xu)
    {
        int realIndex = 0;
        if (a[0] == '-')
        {
            realIndex += 1;
        }
        while(isdigit(a[realIndex])) realIndex++;
        real = stoi(a.substr(0, realIndex));
        int xuIndex = realIndex;
        while(!isdigit(a[xuIndex])) xuIndex++;
        xuIndex -=1;
        xu = stoi(a.substr(xuIndex, a.size()-xuIndex));
    }
};