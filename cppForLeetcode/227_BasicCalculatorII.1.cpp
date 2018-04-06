#include <string>
#include <stack>
#include <functional>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		istringstream in('+' + s + '+');
		long long total = 0, term = 0, n;
		char op;
    	while (in >> op) {
			if (op == '+' or op == '-') {
				total += term;
				in >> term;
				term *= 44 - op;
			} else {
				in >> n;
				if (op == '*')
					term *= n;
				else
					term /= n;
			}
    	}
    	return total;
	}
};

int main(void)
{
	Solution sol;
	cout << sol.calculate(" 2 *12 - 2  +   2 *12 - 3 / 2 ") << endl;
}