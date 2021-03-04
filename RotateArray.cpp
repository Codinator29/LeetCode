/*

https://leetcode.com/problems/rotate-array/

Given an array, rotate the array to the right by k steps, where k is non-negative.

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numSize = nums.size();
        vector<int> temp;
        
        if(k == numSize || numSize == 1)
        {
            return;
        }
        
        k = k % numSize;

        for(int i = numSize - k; i < numSize; i++)
        {
            temp.push_back(nums[i]);
        }
        
        for(int i = numSize - 1; /*i > numSize - k - 1*/ i - k >= 0; i--)
        {
            nums[i] = nums[i - k];
        }
        
        for(int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }
    }
};