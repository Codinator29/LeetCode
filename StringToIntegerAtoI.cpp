/*

https://leetcode.com/problems/string-to-integer-atoi/

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

*/

class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) 
        {
            return 0;
        }
        int idx = 0;
        while(s[idx] == ' ') 
        {
            idx++;
        }
        long long sign = 1ll;  // use long long to speed up.
        if(idx < s.size()) 
        {
            if(s[idx] == '-') 
            {
                sign = -1ll, idx++;
            }
            else if(s[idx] == '+')
            {
                idx++;
            }
        }
        if(idx < s.size() && !isdigit(s[idx])) 
        {
            return 0;
        }
        long long sum = 0;
        while(isdigit(s[idx])) 
        {
            sum = sum * 10 + s[idx] - '0';
            if(sum > (long long) INT_MAX && sign == 1ll) 
            {
                return INT_MAX;
            }
            if(sum > (long long) INT_MAX + 1 && sign == -1ll)
            {
                return INT_MIN;
            }
            idx++;
        }
        return (int) (sum * sign);
    }
};