#include "Common.h"

    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
int main(void)
{
    vector<string> result = generateParenthesis(4);
    for(auto iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *(iter) << endl;
    }
    return 0;
}