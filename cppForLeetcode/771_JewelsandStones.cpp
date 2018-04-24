#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> js;
        for(char c : J)
        {
            js[c] = true;
        }
        int count = 0;
        for(char c : S)
        {
            if(js[c]) count += 1;
        }
        return count;
    }
};