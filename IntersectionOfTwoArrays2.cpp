/*

https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for (auto i : nums1)
            m1[i]++;
        for (auto i : nums2)
            m2[i]++;
        vector<int> v;
        for (auto i : m1) {
            if (m2[i.first]) {
                int x = min(i.second, m2[i.first]);
                while (x) {
                    v.push_back(i.first);
                    x--;
                }
            }
        }
        return v;
    }
};