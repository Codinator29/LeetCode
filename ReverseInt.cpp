/*

https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

*/

class Solution {
public:
    int reverse(int x) {
       
        long reverse = 0;
        
        while(x != 0)
        {
            int dig = x % 10;
            x /= 10;
            
            if(reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
            {
                return 0;
            }
            
            reverse = reverse * 10 + dig;
        }
        
        return reverse;
    }
};