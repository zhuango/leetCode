#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	a = a % b;
	unordered_map<int, int> mapp;
	mapp[a] = 0;
	int step = 0;
	while(true)
	{
		a = a * 10;
		a = a % b;
		if(a == 0 || mapp.count(a) != 0) break;
		
		step ++;
		mapp[a] = step;
	}
	if(a == 0) cout << step +1 << " " << 0 << endl;
	else cout << mapp[a] << " " << step - mapp[a] + 1 << endl;
	return 0;
}
