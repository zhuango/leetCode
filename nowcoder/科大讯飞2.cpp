#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> num(n + 2, -1);
	num[0] = -1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num[i];
	}
	vector<int> temp;
	temp.push_back(-1);
	int night = 0;
	while (true)
	{
        bool b = true;
		for (int i = 1; i <= num.size() - 2; ++i)
		{
			if (num[i] >= num[i - 1])
			{
				temp.push_back(num[i]);
			}
            if(num[i] < num[i-1]) b = false;
		}
        if(b) break;
		swap(num, temp);
		num.push_back(-1);
		temp.clear();
		temp.push_back(-1);
		night += 1;
	}
	cout << night << endl;
	return 0;
}