/*
There are n bulbs that are initially off.You first turn on all the bulbs.Then, you turn off every second bulb.On the third round, you toggle every third bulb(turning on if it's off or turning off if it's on).For the nth round, you only toggle the last bulb.Find how many bulbs are on after n rounds.

Example:

Given n = 3.

At first, the three bulbs are[off, off, off].
After first round, the three bulbs are[on, on, on].
After second round, the three bulbs are[on, off, on].
After third round, the three bulbs are[on, off, off].

So you should return 1, because there is only one bulb is on.

Answer:

for each bulb, it will be toggled only during the round of its factors.
only perfect aquare number has odd factors.

*/
#include "Common.h"
class BulbSwitcher {
public:
	int bulbSwitch(int n) {
		int index, result = 0;
		bool *bulds = new bool[n];
		for(int i = 0; i < n; i++)
		{
			bulds[i] = false;
		}
		for(index = 1; index <= n; index ++)
		{
			for(int i = index - 1; i < n; i = i + index)
			{
				bulds[i] = !bulds[i];
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(bulds[i]) result++;
		}
		return result;
	}

	int buldSwitch(int n)
	{
		return (int)sqrt(n);
	}
};