/*

https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size - 1;
        int leftMax = 0, rightMax = 0;
        int result = 0;
        
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(leftMax < height[left])
                {
                    leftMax = height[left];
                }
                else
                {
                    result += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if(rightMax < height[right])
                {
                    rightMax = height[right];
                }
                else
                {
                    result += rightMax - height[right];
                }
                right--;
            }
        }
        return result;
    }
};