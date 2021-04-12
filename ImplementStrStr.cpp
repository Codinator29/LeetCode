/*

https://leetcode.com/problems/implement-strstr/

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.size();
        int haystackSize = haystack.size();
        
        if(needleSize == 0)
        {
            return 0;
        }
        
        for(int i = 0; i < haystackSize - needleSize + 1; i++)
        {
            int temp = i;
            
            if(haystack[i] == needle[0])
            {
                int j = 1;
                int count = 1;
                while(j < needleSize)
                {
                    if(haystack[++temp] == needle[j])
                    {
                        j++;
                        count++;
                    }
                    else
                    {
                        break;    
                    }
                }
                
                if(count == needleSize)
                {
                    return i;
                }
            }
        }
        
        return -1;
    }
};