/*

https://leetcode.com/problems/factorial-trailing-zeroes/

Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        
        while(n >= 5)
        {
            count += n / 5;
            n /= 5;
        }
        
        return count;
    }
};