#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}
	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		set<int> temp;
		for (int elem : s)
		{
			temp.insert(elem + numbers[i]);
		}
		s.insert(numbers[i]);
		s.insert(temp.begin(), temp.end());
	}
	vector<int> nums;
	for (int elem : s)
	{
		nums.push_back(elem);
	}
	sort(nums.begin(), nums.end());

	int i = 0;
	int j = nums.size() - 1;
	int mid = 0;
	while (i < j)
	{
		mid = (i + j) / 2;
		if (nums[mid] - 1 == mid)
		{
			i = mid + 1;
		}
		else
		{
			j = mid;
		}
	}
	if (nums[j] - 1 == j)
		cout << nums.size() + 1 << endl;
	else
		cout << nums[j] - (nums[j] - j) + 1 << endl;
	return 0;
}