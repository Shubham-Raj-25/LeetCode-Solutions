class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int min_idx = -1, max_idx = -1, out_of_range_idx = -1;

        for(int i=0;i<nums.size();i++){
            
            if(nums[i] < minK || nums[i] > maxK)
                out_of_range_idx = i;
            
            if(nums[i] == minK)
                min_idx = i;
            
            if(nums[i] == maxK) 
                max_idx = i;
            
            int begin_idx = min(min_idx,max_idx);

            if(begin_idx > out_of_range_idx)
                ans += begin_idx - out_of_range_idx;
        
        }

        return ans;
    }
};