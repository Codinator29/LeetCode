/*

https://leetcode.com/problems/plus-one/

Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        
        int carry = 0;
        bool first = true;
        int one = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if(first)
            {
                if(result[i] + one + carry > 9)
                {
                    result[i] = (result[i] + one + carry) % 10;
                    carry = 1;
                    one = 0;
                }
                else
                {
                    result[i] = result[i] + 1;
                    carry = 0;
                    first = false;
                }
                
            }
        }
        
        if(carry > 0)
        {
            result.insert(result.begin(), carry);
        }
        
        return result;
    }
};