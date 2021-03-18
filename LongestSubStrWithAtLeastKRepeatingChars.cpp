/*

https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

*/

class Solution {
public:
      int longestSubstringUtil(const string& s,const int& k,int start, int end) {
        
        if(end - start < k)
            return 0;
        
        vector<int> count (26, 0);
        
        for(int i = start; i < end; i++)
        {
            count[s[i] - 'a']++;
        }
        
        for(int i = start; i < end; i++)
        {
            if(count[s[i] - 'a'] < k)
            {
                int j = i + 1;
               
                while(j < end && count[s[j] - 'a'] < k)
                    j++;
                
                return max(longestSubstringUtil(s, k, j, end), longestSubstringUtil(s, k, start, i));
            }
        }
        
        return end - start;    
    }
    
    int longestSubstring(string s, int k) {
        return longestSubstringUtil(s, k, 0, s.length());
    }
};