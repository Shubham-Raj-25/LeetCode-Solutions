class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        auto upper = upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;

        if(lower>upper) return {-1,-1};

        return {(int)lower,(int)upper};
    }
};