/*

https://leetcode.com/problems/reverse-bits/

Reverse bits of a given 32 bits unsigned integer.

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t A) {
        unsigned int Bits = sizeof(A) * 8;
        unsigned reverse = 0, i , temp;

       for(i = 0; i < Bits; i++){
           temp = (A & (1 << i));

           if(temp){
               reverse |= (1 << ((Bits - 1) - i));
           }
       }

       return reverse; 
       }
};