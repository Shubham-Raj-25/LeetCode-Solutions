class Solution {
public:
    int ans = 0;
    void solve(vector<int>& nums, int target, int value, int idx){
        if(idx == nums.size()){
            if(value == target) ans++;
            return;
        }

        solve(nums, target, value | nums[idx], idx + 1);
        solve(nums, target, value, idx + 1);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(auto i : nums) target |= i;
        solve(nums, target, 0, 0);
        return ans;
    }
};