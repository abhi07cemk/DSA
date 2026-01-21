class Solution {
public:
    double myPow(double x, long long n) {
        // Handle negative power
        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }
        
        double result = 1.0;
        
        while (n > 0) {
            if (n & 1) {          // if n is odd
                result *= x;
            }
            x *= x;              // square the base
            n >>= 1;             // n = n / 2
        }
        
        return result;
    }
};
