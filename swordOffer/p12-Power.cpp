class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (base == 0.0) return 0.0;
        if (exponent < 0) return Power(1.0/base, -exponent);
        double res = 1.0;
        while (exponent) {
            if (exponent & 1) {
                res *= base;
            }
            exponent >>= 1;
            base *= base;
        }
        return res;
    }
};