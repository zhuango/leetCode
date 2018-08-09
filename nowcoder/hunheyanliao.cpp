#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}
	
	for (int i = 0; i < n; ++i)
	{
		sort(numbers.begin() + i, numbers.end(), [](int a, int b) {return a > b; });

		for (int j = i + 1; j < n; ++j)
		{
			if ((numbers[i] ^ numbers[j]) < numbers[j])
			{
				numbers[j] = (numbers[i] ^ numbers[j]);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		if (numbers[i] != 0) result += 1;
	}
	cout << result << endl;
	return 0;
}