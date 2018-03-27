#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseTable = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> codes;
        string temp = "";
        for(string &s : words)
        {
            temp = "";
            for(char c : s)
            {
                temp += morseTable[c -'a'];
            }
            if (temp != "") codes.insert(temp);
        }
        return codes.size();
    }
};