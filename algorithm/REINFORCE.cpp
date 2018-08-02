#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double gain(double gama, vector<double> &reward, double t)
{
    double gain;
    for(int i = t + 1; i < reward.size(); ++i)
    {
        gain += pow(gama, i-t-1) * reward[i];
    }
    return gain;
}

vector<double> policyGrident(double lr, double gama, int T, vector<double> &rewards, vector<double> &grident)
{
    vector<double> grids;
    for(int t = 0; t < T; ++t)
    {
        double grid = lr * pow(gama, t) * gain(gama, rewards, t) * grident[t];
        grids.push_back(grid);
    }
    return grids;
}

int main(void)
{
    double lr = 0.1;
    int T = 10;
    vector<double> rewards = {0, 1, -1, 1, 0 , 2, 1, 1, 0, -1};
    double gama = 1;
    vector<double> gridents = {0.1, 0.2, 0.3, -0.2, 0.56, 0.4, 0.2, 0.11, 0.62, -0.2};
    vector<double> pgrids = policyGrident(lr, gama, T, rewards, gridents);
    for(double f : pgrids)
    {
        cout << f << " ";
    }
    cout << endl;
}