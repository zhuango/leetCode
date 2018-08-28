#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int level = 0;
    for(char c : s)
    {
        if(c == '(') level ++;
    }
    if(level == 0)
    {
        cout << s << endl;
        return 0;
    }
    vector<string> result(level + 1, "");
    int firstR = s.find('(');
    result[0] = s.substr(0, firstR);
    stack<char> st;
    st.push(s[firstR]);
    int i = firstR + 1;
    stack<int> curl;
    curl.push(firstR+1);
    while(!st.empty())
    {
        while(i < s.size() && s[i] != ')') 
        {
            st.push(s[i]);
            if(s[i] == '(') curl.push(i+1);
            i++;
        }
        
        char c = st.top();
        string ss;
        while(c != '(')
        {
            ss.push_back(c);
            st.pop();
            c = st.top();
        }
        reverse(ss.begin(), ss.end());
        st.pop();
        int l = curl.size();
        curl.pop();
        for(int j = 0; j < ss.size(); ++j)
        {
            if(ss[j] == ',') ss[j] = ' ';
        }
        result[l] += ss + " ";
        i++;
    }
    for(string &str : result)
    {
        cout << str << endl;
    }
}