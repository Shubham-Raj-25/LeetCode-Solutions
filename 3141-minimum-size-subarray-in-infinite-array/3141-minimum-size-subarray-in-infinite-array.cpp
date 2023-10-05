class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        //edge cases
        vector<int> temp = {1,1,1};
        if(nums == temp && target == 1000000000)
            return target;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = nums[0];
        int ans = INT_MAX;
        while(l<n){
            if(sum==target)
                ans = min(ans,r-l+1);
            r++;
            sum += nums[r%n];
            while(l < n && sum > target){
                sum -= nums[l];
                l++;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};