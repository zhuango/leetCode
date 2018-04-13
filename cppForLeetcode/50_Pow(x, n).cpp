
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double temp = myPow(x, n / 2);
        if (n % 2) return n < 0 ? 1 / x * temp * temp : x * temp * temp;
        else return temp * temp;
    }
};