/*

https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

*/

class Solution {
public:
    bool isPalindrome(int x) {
       // handle case like x = 21120.
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        // #y means half-tail sum of #x.
        int y = 0;
        while (x > y) {
            y = 10 * y + x % 10;
            x /= 10;
        }
        
        return (x == y || x == y/10); 
    }
};
