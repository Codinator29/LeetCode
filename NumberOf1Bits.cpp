/*

https://leetcode.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

*/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int noOfBits = 0;
        
        for(int i = 0; i < 32; i++)
        {
            if(1 << i & n)
            {
                noOfBits++;
            }
        }
        
        return noOfBits;
    }
};