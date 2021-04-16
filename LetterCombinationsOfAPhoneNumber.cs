/*

https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*/

public class Solution {
    List<string> Map;
    public IList<string> LetterCombinations(string digits) {
        if(digits.Length == 0)
        {
            return new List<string>();
        }
            Map = new List<string>();
            Map.Add("0");
            Map.Add("1");
            Map.Add("abc");
            Map.Add("def");
            Map.Add("ghi");
            Map.Add("jkl");
            Map.Add("mno");
            Map.Add("pqrs");
            Map.Add("tuv");
            Map.Add("wxyz");
        
            List<string> ans = new List<string>();
            string current = string.Empty;
            generateHelper(current, 0, digits, ans);
            return ans;
    }
    
    void generateHelper(string current, int index, string digits, List<string> ans){
        if(index == digits.Length){
            ans.Add(current);
            return;
        }
        
        int digit = digits[index] - '0';
        
        for(int i = 0; i < Map[digit].Length; i++){
            current = current + Map[digit][i];
            generateHelper(current, index + 1, digits, ans);
            current = current.Remove(current.Length - 1);
        }
        
        return;
    }
}