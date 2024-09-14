class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int num : nums) maxi = max(maxi,num);
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            int len = 0;
            while(i < nums.size() && nums[i] == maxi){
                len++;
                i++;
            } 
            ans = max(len,ans);
        }
        return ans;
    }
};