/*

https://leetcode.com/problems/divide-two-integers/

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
       int sign = (dividend < 0) ^ (divisor < 0) ? -1: 1;
       long long int n = abs(dividend);
       long long int m = abs(divisor);
       long long int temp = 0;
       long long int q = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(temp + (m << i) <= n)
            {
                temp += m << i;
                q = q | (1ll << i);
            }
        }
       q = (sign < 0) ? -q : q;
       return  (q >= INT_MAX || q < INT_MIN) ? INT_MAX : q;
 
    }
};