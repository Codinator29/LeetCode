/*

https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (!strs.size()){
            return res;
        }

        string prev = strs[0];
        int end = prev.size() - 1;
        for (int i = 1; i < strs.size(); i++) {
            string curr = strs[i];
            for (int j = 0; j <= end; j++) {
                if (prev[j] != curr[j]) {
                    if (j == 0){
                        return res;
                    }
                    end = j - 1;
                    break;
                }
            }
        }

        for (int k = 0; k <= end; k++){
            res += prev[k];
        }

        return res;
    }
};