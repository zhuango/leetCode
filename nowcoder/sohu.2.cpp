#include <iostream>
#include <string>

using namespace std;

int getnextNumber(const string &s, unsigned int &index)
{
	int num = 0;
	while (index < s.size() && isdigit(s[index]))
	{
		num = num * 10 + s[index] - '0';
		index++;
	}
	return num;
}

int compareVersionNumber(const string& x, const string& y) {
	unsigned int indexx = 0;
	unsigned int indexy = 0;
	while (indexx < x.size() && indexy < y.size())
	{
		int verx = getnextNumber(x, indexx);
		int very = getnextNumber(y, indexy);
		if (verx > very) return 1;
		if (verx < very) return -1;
		indexx += 1;
		indexy += 1;
	}
	if (indexx >= x.size() && indexy >= y.size()) return 0;
	if (indexx < x.size())
	{
		bool notzero = false;
		while (indexx < x.size())
		{
			int verx = getnextNumber(x, indexx);
			indexx += 1;
			if (verx != 0)
			{
				notzero = true;
				break;
			}
		}
		if (notzero)
			return 1;
		else return 0;
	}
	bool notzero = false;
	while (indexy < y.size())
	{
		int very = getnextNumber(y, indexy);
		indexy += 1;
		if (very != 0)
		{
			notzero = true;
			break;
		}
	}
	if (notzero)
		return -1;
	else return 0;

}

int main() {
	string x;
	string y;
	cin >> x >> y;
	cout << compareVersionNumber(x, y);
	return 0;
}
