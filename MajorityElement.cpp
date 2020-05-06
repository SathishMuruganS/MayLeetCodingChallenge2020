/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

**/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto ii: nums){
            if(mp.find(ii) != mp.end()){
                mp[ii]++;
            }else{
                mp[ii] = 1;
            }
        }
        
        int mid = nums.size()/2;
        int best = INT_MIN;
        int count = 0;
        for(auto ii : nums){
            if (mp[ii] >= mid && count < mp[ii]) {
                best = ii;
                count = mp[ii];
            }
        }
        return best;
    }
};
