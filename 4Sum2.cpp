/*

https://leetcode.com/problems/4sum-ii/

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.


*/

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int,int> m;
        for(auto x : a){
            for(auto y : b){
                m[x+y]++;
            }
        }
        int ans=0;
        for(auto x : c){
            for(auto y : d){
                if(m.find(-(x+y))!=m.end()){
                    ans+=m[-(x+y)];
                }
            }
        }
        return ans;
    }
};