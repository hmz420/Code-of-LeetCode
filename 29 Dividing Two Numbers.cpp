/*
解法1：暴力解法：直接用除数来累计计算被除数中的除数的个数;
解法2：指数逼近：通过>>使被除数以2的阶乘的速度缩小，在刚好得到余数大于或者等于除数时，对剩余部分用同样的方法进行缩小;
 */

class Solution {
public:
    #define MAX_MY 0x80000000
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        else if(dividend == 0) {
            return 0;
        }
        unsigned int res(0);
        int flag = (dividend ^ divisor) < 0? -1 : 1;
        unsigned int dividend_un = dividend == INT_MIN? MAX_MY : abs(dividend);
        unsigned int divisor_un = divisor == INT_MIN? MAX_MY : abs(divisor);
        if(dividend_un < divisor_un) {
            return 0;
        }
        for(int i(31); i >= 0; --i) {
            if((dividend_un >> i) >= divisor_un) {
                res += 1 << i;
                dividend_un -= divisor_un << i;
            }
        }
        return flag * res;
    }
};

