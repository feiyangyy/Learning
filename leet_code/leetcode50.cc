class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) {
            return 0;
        }
        if (n < 0) {
            x = 1/x;
            n = std::abs(n);
        } else if(!n) {
            return 1;
        }
        double res = 1;
        while(n > 0){
            if(n & 1){
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};