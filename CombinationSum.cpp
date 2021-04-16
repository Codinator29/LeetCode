/*

https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> combinations;
        vector<vector<int>> result;
        findTargetSum(candidates, result, combinations, target, 0, 0);
        return result;
    
    }

    void findTargetSum(vector<int> &candidates, vector<vector<int>> &result, vector<int> &combinations, int     target, int start, int sum) 
    {

        if (sum > target) 
            return;

        else if (sum == target) 
        {
            result.push_back(combinations);
        }
        else 
        {
            for (int i = start; i < candidates.size(); i++) 
            {
                combinations.push_back(candidates[i]);
                findTargetSum(candidates, result, combinations, target, i, sum + candidates[i]);
                combinations.pop_back();
            }
            return;
        }

    }
};