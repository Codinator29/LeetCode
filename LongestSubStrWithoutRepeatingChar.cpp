/*

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.


Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0)
        {
            return 0;
        }
        
        unordered_set<int> set;
        int start = 0;
        int maxCount = INT_MIN;
        int count = 0;
        
        for(int end = 0; end < s.size(); end++)
        {
            if(set.find(s[end]) == set.end())
            {
                set.insert(s[end]);
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                while(set.find(s[end]) != set.end())
                {
                    set.erase(s[start]);
                    start++;
                    count--;
                }
                set.insert(s[end]);
                count++;
            }
        }
        
        return maxCount;
    }
};
