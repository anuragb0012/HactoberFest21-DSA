/*
Github:- Gupta-Nikhil85
Question URL:- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // TC:- O(NlogN)
        
        //checking if nums had no value.
        //then returning -1,-1.
        
        if(nums.size()==0) return {-1,-1};
        
        //lower_bound and upper_bound returns the iterator of the lower bound and upper bound of a particular number.
        //So to get the index, subtracting nums.begin() from them.
        //Subtracting 1 from upper bound as it returns the iterator of next value.        
        
        int lowidx= (lower_bound(nums.begin(), nums.end(), target)- nums.begin());
        int uppidx= (upper_bound(nums.begin(), nums.end(), target)- nums.begin())-1;
        
        //Checking if nums[lowidx] and nums[uppidx] are equal to target, then returning
        // values of lowidx and uppidx.
        // Also checking if lowidx and uppidx don't cause any segmentation error.
        
        if(lowidx <nums.size() && uppidx <nums.size() && nums[lowidx]==target && nums[lowidx]== target) 
            return {lowidx, uppidx}; 

        return {-1,-1};

    }
};