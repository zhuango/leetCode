#include <string>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        bases = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4};
        mapping[1000] = "M";
        mapping[900]  = "CM";
        mapping[500]  = "D";
        mapping[400]  = "CD";
        mapping[100]  = "C";
        mapping[90]   = "XC";
        mapping[50]   = "L";
        mapping[40]   = "XL";
        mapping[10]   = "X";
        mapping[9]    = "IX";
        mapping[5]    = "V";
        mapping[4]    = "IV";
    }
    string intToRoman(int num) {
        stringstream ss;
        int start = 0;
        while(start < 12 && bases[start] > num)
        {
            start += 1;
        }
        int base = 0;
        for(;start < 12; ++start)
        {
            base = bases[start];
            for (int i = 0; i < num / base; ++i)
            {
                ss << mapping[base];
            }
            num = num % base;
            if (num <= 3) break;
        }
        for (int i = 0; i < num; ++i)
        {
            ss << "I";
        }
        return ss.str();
    }

private:
    unordered_map<int, string> mapping;
    vector<int> bases;
};

int main(void)
{
    Solution sol;
    cout << "0:  " << sol.intToRoman(0) << endl;
    cout << "1:  " << sol.intToRoman(1) << endl;
    cout << "2:  " << sol.intToRoman(2) << endl;
    cout << "3:  " << sol.intToRoman(3) << endl;
    cout << "4:  " << sol.intToRoman(4) << endl;
    cout << "5:  " << sol.intToRoman(5) << endl;
    cout << "9:  " << sol.intToRoman(9) << endl;
    cout << "10: " << sol.intToRoman(10) << endl;
    cout << "11: " << sol.intToRoman(11) << endl;
    cout << "14: " << sol.intToRoman(14) << endl;
    cout << "15: " << sol.intToRoman(15) << endl;
    cout << "29: " << sol.intToRoman(29) << endl;
    cout << "58: " << sol.intToRoman(58) << endl;
    cout << "1994: " << sol.intToRoman(1994) << endl;
}