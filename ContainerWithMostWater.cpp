/*

https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int result = 0;
        
        while(left < right)
        {
            result = max(result, (right - left) * min(height[left], height[right]));
            
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;  
            }
        }
        
        return result;
    }
};