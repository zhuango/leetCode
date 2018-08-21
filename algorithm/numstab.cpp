#include <iostream>
using namespace std;

void overflow()
{
    double a = exp(998);
    double b = exp(1000);

    double c = 0;
    for(int i = 0; i < 100; ++i)
    {
        c += exp(-2);
    }
    cout << 1000 + log(c + 1)  << endl;
    cout << log(b + a *100) << endl; 
}

void underflow()
{
    double a = exp(-1000);
    double b = exp(-999);

    double c = 0;
    for(int i = 0; i < 100; ++i)
    {
        c += exp(-1);
    }
    cout << -999 + log(c + 1)  << endl;
    cout << log(b + a *100) << endl; 
}
int main(void)
{
    overflow();
    underflow();
    return 0;
}