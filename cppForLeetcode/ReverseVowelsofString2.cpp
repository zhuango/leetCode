#include "Common.h"
class Solution {
public:
    string reverseVowels(string s){
        map<char, bool> vovels;
        vovels.insert(pair<char, bool>('A',true));
        vovels.insert(pair<char, bool>('E',true));
        vovels.insert(pair<char, bool>('I',true));
        vovels.insert(pair<char, bool>('O',true));
        vovels.insert(pair<char, bool>('U',true));
        vovels.insert(pair<char, bool>('a',true));
        vovels.insert(pair<char, bool>('e',true));
        vovels.insert(pair<char, bool>('i',true));
        vovels.insert(pair<char, bool>('o',true));
        vovels.insert(pair<char, bool>('u',true));

        char alp[24] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', ',', '.', '!'}
        for(int i = 0; i < 24; i++)
        {
            vovels.insert(pair<char, bool>(alp[i],false));
        }

        index = 0
        tailIndex = -1
        length = 
        //#########################
        //t0 = time.time()
        //#########################
                            
        while index + abs(tailIndex) < length:
            while (index < length) and (not vovels[tmplist[tailIndex]]) :
                index += 1
            while (abs(tailIndex) <= length) and (not vovels[tmplist[tailIndex]]):
                tailIndex -= 1
            if(index + abs(tailIndex) < length):
                tmp = tmplist[index]
                tmplist[index] = tmplist[tailIndex]
                tmplist[tailIndex] = tmp
                index += 1
                tailIndex -= 1
    }
};

int main(void)
{
    so = Solution()
}