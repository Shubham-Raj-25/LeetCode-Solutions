class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix(n,1), suffix(n,1);
        
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1])
                prefix[i] = prefix[i-1] + 1;
            else
                prefix[i] = 1;
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1])
                suffix[i] = suffix[i+1] + 1;
            else
                suffix[i] = 1;
        }

        for(int i=0;i<n-1;i++)
            ans = max(ans, min(suffix[i+1],prefix[i]));
        
        return ans;
    }
};