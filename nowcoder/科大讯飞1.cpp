#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int m;
        float x;
        int nn =0;
        cin >> m >> x;
        float ave = 0;
        
        vector<float> s(m, 0);
        for(int j = 0; j < m; ++j)
        {
            cin >> s[j];
            ave += s[j];
        }
        if(ave >= x * s.size())
        {
            cout << 0 << endl;
        }
        else
        {
            sort(s.begin(), s.end());
            for(int j = 0; j < s.size(); ++j)
            {
                ave += 100 - s[j];
                nn ++;
                if(ave >= x * s.size()) 
                {
                    cout << nn << endl;
                    break;
                }
            }
        }
        
    }
	return 0;
}