#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    double h;
    cin >> h;
    cout << long(sqrt((0.25+h)) - 0.5) << endl;
    return 0;
}

