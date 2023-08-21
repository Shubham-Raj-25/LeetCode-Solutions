class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        int ans = 1;

        int left= 0;

        for(int right=0;right<nums.size();right++){
            
            ans = max(ans,++freq[nums[right]]);

            if(right - left -ans + 1 > k) // as we can remove max k elements
                --freq[nums[left++]];
        }

        return ans;
    }
};