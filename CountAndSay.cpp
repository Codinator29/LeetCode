/*

https://leetcode.com/problems/count-and-say/

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.

*/

class Solution {
public:
    string countAndSay(int n) 
    {
        string digit_str ="1";
        if(n <= 0) 
        {
            return "-1";
        }
     
        for(int j = 1; j < n; j++){
            int size = digit_str.size();
            int i = 0;
            string temp = "";
            while(i < size)
            {
                char c = digit_str[i];
                int  count = 0;
                
                while(i < size && digit_str[i] == c)
                {
                    count++;
                    i++;
                }
                char t = '0'+ count;
                temp += t ;
                temp += c;

            }
            digit_str = temp;
            
        }
        return digit_str;
    }
};