/*

https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

*/

class Solution {
public:
    vector<string> ans;
    void soln(int n, int open, int close,string temp){
        if (close == n){
            ans.push_back(temp);
        }
        if(open < n){
            //string nt = temp + '(';
            soln(n, open + 1, close, temp + '(');
        }
        if(open > close){
            //string nt = temp +')';
            soln(n, open, close + 1, temp + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        soln(n, 0, 0, "");
        return ans;
    }
};