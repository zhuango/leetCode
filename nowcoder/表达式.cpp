#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int getnextNumber(string &s, int &index)
{
	int num = 0;
	while (index < s.size() && s[index] >= '0' && s[index] <= '9')
	{
		num *= 10;
		num += s[index] - '0';
		index += 1;
	}
	return num;
}
int main(void)
{
	string s;
	cin >> s;
	int index = 0;
	stack<int> st;
	stack<char> op;
    if(s[0] == '-')
    {
        index += 1;
        int num = getnextNumber(s, index);
        st.push(-num);
    }
    else if(s[0] == '+')
    {
        index += 1;
        int num = getnextNumber(s, index);
        st.push(num);
    }
    char oo = 'n';
	while (index < s.size())
	{
		int oldindex = index;
		int num = getnextNumber(s, index);
		if (oldindex != index)
		{
            oo = 'n';
			st.push(num);
			continue;
		}
		if (s[index] == '-')
		{
			index++;
			int temp = getnextNumber(s, index);
            
			if(oo == '*' || oo == '/') num = 0;
            else
            {
                num = st.top();
                st.pop();
            }
			num = num - temp;
			st.push(num);
            oo = '-';
		}
		else if (s[index] == '+')
		{
			index++;
			int temp = getnextNumber(s, index);
			if(oo == '*' || oo == '/') num = 0;
            else
            {
                num = st.top();
                st.pop();
            }
			num = num + temp;
			st.push(num);
            oo = '+';
		}
		else
		{
            oo = s[index];
			op.push(s[index]);
			index += 1;
		}

	}
	while (!op.empty())
	{
		char o = op.top();
		op.pop();
		if (o == '*')
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			a = b * a;
			st.push(a);
		}
		else if (o == '/')
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			a = b / a;
			st.push(a);
		}
	}
	cout << st.top() << endl;

	return 0;
}