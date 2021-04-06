/*

https://leetcode.com/problems/3sum-closest/

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(), nums.end());
        
        int ans;
        int _min=INT_MAX;
        for( int i=0;i<n-2;i++){
            
            int start=i+1;
            int end=n-1;
            
            while(start<end){
                
                int sum=nums[i]+nums[start]+nums[end];
                if(sum == target )
                    return target;
                    
                if(_min>abs(sum-target)){
                    _min=abs(sum-target);
                    ans=sum;
                }
                
                if(sum>target)
                    end--;
                else start++;
                
            }
        }
        
        return ans;
    }
};