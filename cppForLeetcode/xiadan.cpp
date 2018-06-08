#include <iostream>
#include <vector>

using namespace std;
int main() {
    int m,n;
    cin >> n >> m;
    vector<vector<double>> counts(n, vector<double>(2, 0));
    vector<vector<double>> cut(m, vector<double>(2, 0));
    for(int i = 0; i < n; ++i)
    {
        cin >> counts[i][0] >> counts[i][1];
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> cut[i][0] >> cut[i][1];
    }
    double countR = 0.0;
    double noCount = 0.0;
    for(int i = 0; i < n; ++i)
    {
        if(counts[i][1] == 1)
        {
            countR += counts[i][0] * 0.8;
        }
        else
        {
            countR += counts[i][0];
        }
        noCount += counts[i][0];
    }
    for(int i = 0; i < m; ++i)
    {
        if(noCount >= cut[i][0] && noCount - cut[i][1] < countR)
        {
            countR = noCount - cut[i][1];
        }
    }
    printf("%.2f\n", countR);
    return 0;
}